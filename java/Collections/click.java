import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class click {
    JLabel jlab;
    click(){
        JFrame jfrm = new JFrame("A Click");
        jfrm.setLayout(new FlowLayout());
        jfrm.setSize(220,90);
        jfrm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        JButton jbtnAlp = new JButton("Male");
        JButton jbtnBt = new JButton("Female");
        jbtnAlp.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                jlab.setText("\nMale was chosen.");
            }
        });
        jbtnBt.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent ae) {
                jlab.setText("\nFemale was chosen.");
            }
        });
        jfrm.add(jbtnAlp);
        jfrm.add(jbtnBt);
        jlab = new JLabel("Choose an option");
        jfrm.add(jlab);
        jfrm.setVisible(true);
    }
    public static void main (String[] args){
        SwingUtilities.invokeLater(new Runnable() {
            @Override
            public void run() {
                new click();
            }
        });
    }
}
