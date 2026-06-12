import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class SimpleSwingApp {

    public static void main(String[] args) {
        // Run on the Event Dispatch Thread
        SwingUtilities.invokeLater(() -> createAndShowGUI());
    }

    private static void createAndShowGUI() {
        // --- Main Frame ---
        JFrame frame = new JFrame("Simple Swing App");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 220);
        frame.setLocationRelativeTo(null); // Center on screen

        // --- Panel with padding ---
        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        panel.setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        GridBagConstraints gbc = new GridBagConstraints();
        gbc.insets = new Insets(8, 8, 8, 8);
        gbc.fill = GridBagConstraints.HORIZONTAL;

        // --- Label ---
        JLabel label = new JLabel("Enter your name:");
        gbc.gridx = 0; gbc.gridy = 0; gbc.weightx = 0;
        panel.add(label, gbc);

        // --- Text Field ---
        JTextField textField = new JTextField(20);
        gbc.gridx = 1; gbc.gridy = 0; gbc.weightx = 1;
        panel.add(textField, gbc);

        // --- Button ---
        JButton button = new JButton("Say Hello");
        gbc.gridx = 0; gbc.gridy = 1; gbc.gridwidth = 2; gbc.weightx = 0;
        gbc.fill = GridBagConstraints.NONE;
        gbc.anchor = GridBagConstraints.CENTER;
        panel.add(button, gbc);

        // --- Output Label ---
        JLabel outputLabel = new JLabel(" ", SwingConstants.CENTER);
        outputLabel.setFont(new Font("SansSerif", Font.BOLD, 14));
        outputLabel.setForeground(new Color(0x185FA5));
        gbc.gridx = 0; gbc.gridy = 2; gbc.gridwidth = 2;
        gbc.fill = GridBagConstraints.HORIZONTAL;
        panel.add(outputLabel, gbc);

        // --- Button Action ---
        button.addActionListener(e -> {
            String name = textField.getText().trim();
            if (name.isEmpty()) {
                outputLabel.setForeground(new Color(0xA32D2D));
                outputLabel.setText("Please enter a name!");
            } else {
                outputLabel.setForeground(new Color(0x185FA5));
                outputLabel.setText("Hello, " + name + "! 👋");
            }
        });

        // Allow pressing Enter in the text field to trigger the button
        textField.addActionListener(button.getActionListeners()[0]);

        frame.add(panel);
        frame.setVisible(true);
    }
}
