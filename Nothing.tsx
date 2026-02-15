import React, { useState, useEffect } from 'react';
import { View, Text, TextInput, TouchableOpacity, ScrollView, StyleSheet } from 'react-native';
import AsyncStorage from '@react-native-async-storage/async-storage';
import { tokens } from './src/styles/tokens';

interface Quote {
  id: string;
  text: string;
  author: string;
}

export default function App() {
  const [quotes, setQuotes] = useState<Quote[]>([]);
  const [currentQuoteIndex, setCurrentQuoteIndex] = useState(0);
  const [showManagement, setShowManagement] = useState(false);
  const [rotationTime, setRotationTime] = useState('09:00');
  const [editingQuote, setEditingQuote] = useState<Quote | null>(null);
  const [newQuoteText, setNewQuoteText] = useState('');
  const [newQuoteAuthor, setNewQuoteAuthor] = useState('');

  useEffect(() => {
    loadData();
  }, []);

  const loadData = async () => {
    try {
      const savedQuotes = await AsyncStorage.getItem('quotes');
      const savedTime = await AsyncStorage.getItem('rotationTime');
      const savedIndex = await AsyncStorage.getItem('currentQuoteIndex');
      const lastRotation = await AsyncStorage.getItem('lastRotation');

      if (savedQuotes) {
        const quotesArray = JSON.parse(savedQuotes);
        setQuotes(quotesArray);
      } else {
        const defaultQuotes: Quote[] = [
          { id: '1', text: 'The only way to do great work is to love what you do.', author: 'Steve Jobs' },
          { id: '2', text: 'Life is what happens when you\'re busy making other plans.', author: 'John Lennon' },
        ];
        setQuotes(defaultQuotes);
        await AsyncStorage.setItem('quotes', JSON.stringify(defaultQuotes));
      }

      if (savedTime) setRotationTime(savedTime);
      const index = savedIndex ? parseInt(savedIndex) : 0;
      setCurrentQuoteIndex(index);

      checkRotation(lastRotation, savedTime || '09:00', index);
    } catch (error) {
      console.error('Error loading data:', error);
    }
  };

  const checkRotation = async (lastRotation: string | null, rotTime: string, currentIndex: number) => {
    const now = new Date();
    const [hours, minutes] = rotTime.split(':').map(Number);
    const rotationToday = new Date(now.getFullYear(), now.getMonth(), now.getDate(), hours, minutes);

    if (!lastRotation) {
      await AsyncStorage.setItem('lastRotation', now.toISOString());
      return;
    }

    const lastRotDate = new Date(lastRotation);

    if (now >= rotationToday && lastRotDate < rotationToday) {
      const savedQuotes = await AsyncStorage.getItem('quotes');
      if (savedQuotes) {
        const quotesArray = JSON.parse(savedQuotes);
        if (quotesArray.length > 0) {
          const newIndex = (currentIndex + 1) % quotesArray.length;
          setCurrentQuoteIndex(newIndex);
          await AsyncStorage.setItem('currentQuoteIndex', newIndex.toString());
          await AsyncStorage.setItem('lastRotation', now.toISOString());
        }
      }
    }
  };

  const saveQuotes = async (newQuotes: Quote[]) => {
    setQuotes(newQuotes);
    await AsyncStorage.setItem('quotes', JSON.stringify(newQuotes));
  };

  const handleCreateQuote = async () => {
    if (!newQuoteText.trim()) return;

    const newQuote: Quote = {
      id: Date.now().toString(),
      text: newQuoteText,
      author: newQuoteAuthor || 'Anonymous',
    };

    const updatedQuotes = [...quotes, newQuote];
    await saveQuotes(updatedQuotes);
    setNewQuoteText('');
    setNewQuoteAuthor('');
  };

  const handleEditQuote = async () => {
    if (!editingQuote || !editingQuote.text.trim()) return;

    const updatedQuotes = quotes.map(q => q.id === editingQuote.id ? editingQuote : q);
    await saveQuotes(updatedQuotes);
    setEditingQuote(null);
  };

  const handleDeleteQuote = async (id: string) => {
    const updatedQuotes = quotes.filter(q => q.id !== id);
    await saveQuotes(updatedQuotes);
    if (currentQuoteIndex >= updatedQuotes.length) {
      const newIndex = Math.max(0, updatedQuotes.length - 1);
      setCurrentQuoteIndex(newIndex);
      await AsyncStorage.setItem('currentQuoteIndex', newIndex.toString());
    }
  };

  const handleRotationTimeChange = async (time: string) => {
    setRotationTime(time);
    await AsyncStorage.setItem('rotationTime', time);
  };

  const currentQuote = quotes[currentQuoteIndex];

  return (
    <View style={styles.container}>
      {currentQuote && !showManagement && (
        <View style={styles.quoteContainer}>
          <Text style={styles.quoteText} numberOfLines={4}>
            "{currentQuote.text}"
          </Text>
          <Text style={styles.authorText} numberOfLines={1}>
            — {currentQuote.author}
          </Text>
        </View>
      )}

      <TouchableOpacity
        style={styles.actionButton}
        onPress={() => setShowManagement(!showManagement)}
      >
        <Text style={styles.actionButtonText}>⋯</Text>
      </TouchableOpacity>

      {showManagement && (
        <View style={styles.modal}>
          <ScrollView style={styles.modalScroll} contentContainerStyle={styles.modalContent}>
            <View style={styles.modalHeader}>
              <Text style={styles.modalTitle}>MANAGE</Text>
              <TouchableOpacity onPress={() => setShowManagement(false)}>
                <Text style={styles.closeButton}>✕</Text>
              </TouchableOpacity>
            </View>

            <View style={styles.section}>
              <Text style={styles.sectionLabel}>ROTATION TIME</Text>
              <TextInput
                value={rotationTime}
                onChangeText={handleRotationTimeChange}
                placeholder="HH:MM"
                placeholderTextColor={tokens.colors['secondary-light']}
                style={styles.input}
              />
            </View>

            <View style={styles.section}>
              <Text style={styles.sectionLabel}>ADD QUOTE</Text>
              <TextInput
                value={newQuoteText}
                onChangeText={setNewQuoteText}
                placeholder="Quote text..."
                placeholderTextColor={tokens.colors['secondary-light']}
                multiline
                style={[styles.input, styles.textarea]}
              />
              <TextInput
                value={newQuoteAuthor}
                onChangeText={setNewQuoteAuthor}
                placeholder="Author"
                placeholderTextColor={tokens.colors['secondary-light']}
                style={styles.input}
              />
              <TouchableOpacity style={styles.button} onPress={handleCreateQuote}>
                <Text style={styles.buttonText}>ADD</Text>
              </TouchableOpacity>
            </View>

            <View style={styles.section}>
              <Text style={styles.sectionLabel}>YOUR QUOTES</Text>
              {quotes.map((quote) => (
                <View key={quote.id} style={styles.quoteItem}>
                  {editingQuote?.id === quote.id ? (
                    <View>
                      <TextInput
                        value={editingQuote.text}
                        onChangeText={(text) => setEditingQuote({ ...editingQuote, text })}
                        multiline
                        style={[styles.input, styles.textarea]}
                      />
                      <TextInput
                        value={editingQuote.author}
                        onChangeText={(author) => setEditingQuote({ ...editingQuote, author })}
                        style={styles.input}
                      />
                      <View style={styles.buttonRow}>
                        <TouchableOpacity style={[styles.buttonSmall, { flex: 1 }]} onPress={handleEditQuote}>
                          <Text style={styles.buttonSmallText}>SAVE</Text>
                        </TouchableOpacity>
                        <TouchableOpacity style={[styles.buttonSmall, { flex: 1 }]} onPress={() => setEditingQuote(null)}>
                          <Text style={styles.buttonSmallText}>CANCEL</Text>
                        </TouchableOpacity>
                      </View>
                    </View>
                  ) : (
                    <View>
                      <Text style={styles.quoteItemText} numberOfLines={2}>"{quote.text}"</Text>
                      <Text style={styles.quoteItemAuthor} numberOfLines={1}>— {quote.author}</Text>
                      <View style={styles.buttonRow}>
                        <TouchableOpacity style={[styles.buttonSmall, { flex: 1 }]} onPress={() => setEditingQuote(quote)}>
                          <Text style={styles.buttonSmallText}>EDIT</Text>
                        </TouchableOpacity>
                        <TouchableOpacity style={[styles.buttonSmall, { flex: 1 }]} onPress={() => handleDeleteQuote(quote.id)}>
                          <Text style={styles.buttonSmallText}>DELETE</Text>
                        </TouchableOpacity>
                      </View>
                    </View>
                  )}
                </View>
              ))}
            </View>
          </ScrollView>
        </View>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    width: '100%',
    height: '100%',
    backgroundColor: tokens.colors.dark,
    borderRadius: 22,
    padding: tokens.spacing[4],
    overflow: 'hidden',
  },
  quoteContainer: {
    flex: 1,
    justifyContent: 'center',
    alignItems: 'center',
    paddingHorizontal: tokens.spacing[2],
  },
  quoteText: {
    ...tokens.textStyles.bodyMedium,
    fontSize: 15,
    lineHeight: 22,
    color: tokens.colors.light,
    textAlign: 'center',
    marginBottom: tokens.spacing[3],
  },
  authorText: {
    ...tokens.textStyles.labelSmall,
    color: tokens.colors['secondary-light'],
    textAlign: 'center',
  },
  actionButton: {
    position: 'absolute',
    bottom: tokens.spacing[2],
    right: tokens.spacing[2],
    width: 32,
    height: 32,
    borderRadius: 16,
    backgroundColor: tokens.colors['secondary-dark'],
    justifyContent: 'center',
    alignItems: 'center',
  },
  actionButtonText: {
    color: tokens.colors.light,
    fontSize: 18,
    fontWeight: '600',
  },
  modal: {
    position: 'absolute',
    top: 0,
    left: 0,
    right: 0,
    bottom: 0,
    backgroundColor: tokens.colors.dark,
    borderRadius: 22,
  },
  modalScroll: {
    flex: 1,
  },
  modalContent: {
    padding: tokens.spacing[4],
    flexGrow: 1,
  },
  modalHeader: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    alignItems: 'center',
    marginBottom: tokens.spacing[4],
  },
  modalTitle: {
    ...tokens.textStyles.labelUppercasedMedium,
    color: tokens.colors.light,
    fontSize: 14,
  },
  closeButton: {
    color: tokens.colors.light,
    fontSize: 20,
    fontWeight: '300',
  },
  section: {
    marginBottom: tokens.spacing[5],
  },
  sectionLabel: {
    ...tokens.textStyles.labelUppercasedSmall,
    color: tokens.colors['secondary-light'],
    marginBottom: tokens.spacing[2],
  },
  input: {
    ...tokens.textStyles.bodyMedium,
    backgroundColor: tokens.colors['secondary-dark'],
    borderRadius: tokens.borderRadius.md,
    padding: tokens.spacing[2],
    color: tokens.colors.light,
    marginBottom: tokens.spacing[2],
  },
  textarea: {
    minHeight: 60,
    textAlignVertical: 'top',
  },
  button: {
    backgroundColor: tokens.colors.red,
    borderRadius: tokens.borderRadius.md,
    padding: tokens.spacing[2],
    alignItems: 'center',
  },
  buttonText: {
    ...tokens.textStyles.labelMedium,
    color: tokens.colors.light,
  },
  buttonSmall: {
    backgroundColor: tokens.colors['secondary-dark'],
    borderRadius: tokens.borderRadius.md,
    padding: tokens.spacing[2],
    alignItems: 'center',
    flexShrink: 1,
  },
  buttonSmallText: {
    ...tokens.textStyles.labelSmall,
    color: tokens.colors.light,
  },
  buttonRow: {
    flexDirection: 'row',
    gap: tokens.spacing[2],
    marginTop: tokens.spacing[2],
  },
  quoteItem: {
    backgroundColor: tokens.colors['secondary-dark'],
    borderRadius: tokens.borderRadius.md,
    padding: tokens.spacing[3],
    marginBottom: tokens.spacing[2],
  },
  quoteItemText: {
    ...tokens.textStyles.bodySmall,
    color: tokens.colors.light,
    marginBottom: tokens.spacing[1],
  },
  quoteItemAuthor: {
    ...tokens.textStyles.labelSmall,
    color: tokens.colors['secondary-light'],
    marginBottom: tokens.spacing[2],
  },
});
