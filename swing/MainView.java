import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.*;
import java.net.*;

public class MainView extends JFrame {

    private JTextArea outputTextArea;
    private JButton findButton;
    private JButton playButton;
    private JButton showAllMultimediaButton;
    private JButton showAllGroupButton;

    

    public MainView(Client client) {
          
        // Set up the main frame
        setTitle("Multimedia Application");
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLayout(new BorderLayout());

        // Create text area with scroll bars
        outputTextArea = new JTextArea(10, 30);
        outputTextArea.setFont(new Font("Apple Color Emoji", Font.PLAIN, 12));
        JScrollPane scrollPane = new JScrollPane(outputTextArea);
        add(scrollPane, BorderLayout.CENTER);

        // Create buttons
        JPanel buttonPanel = new JPanel(new GridLayout(3, 2, 5, 5));

        findButton = new JButton("Find Multimedia");

        findButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String multimediaName = JOptionPane.showInputDialog("Enter the name of the Multimedia:");
                outputTextArea.setText(""); // Clear the JTextArea
                outputTextArea.append("Finding Multimedia: " + multimediaName + "\n");
                String response = client.send("findMultimedia " + multimediaName);
               
                response = response.replace(",", "\n");
                outputTextArea.append(response + "\n");
               //System.out.println("Response : " + response);
            }
        });

        playButton = new JButton("Play Multimedia");
        playButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                String multimediaName = JOptionPane.showInputDialog("Enter the name of the Multimedia:");
                outputTextArea.setText(""); // Clear the JTextArea
                outputTextArea.append("Playing Multimedia: " + multimediaName + "\n");
                String response = client.send("playMultimedia " + multimediaName);
                outputTextArea.append("Server Response: " + response + "\n");
            }
        });

        JButton quitButton = new JButton("Quit App");
        quitButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                System.exit(0);
            }
        });

        JButton showAllMultimediaButton = new JButton("Show All Multimedia");
        showAllMultimediaButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                outputTextArea.setText(""); // Clear the JTextArea
                outputTextArea.append("Displaying all Multimedia\n");
                String response = client.send("getAllMultimedia");
                response = response.replace(",", "\n");
                outputTextArea.append(response + "\n");
            }
        });

        showAllGroupButton = new JButton("Show All Group");
        showAllGroupButton.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                outputTextArea.setText(""); // Clear the JTextArea
                outputTextArea.append("Displaying all Groups\n\n");
                String response = client.send("showAllGroup");
                response = response.replace(",", "\n");
                outputTextArea.append(response);
            }
        });

        buttonPanel.add(findButton);
        buttonPanel.add(playButton);
        buttonPanel.add(quitButton);
        buttonPanel.add(showAllMultimediaButton);
        buttonPanel.add(showAllGroupButton);

        add(buttonPanel, BorderLayout.SOUTH);

        // Set size, pack, and make visible
        pack();
        setVisible(true);
    }


    public JTextArea getOutputTextArea() {
        return outputTextArea;
    }

    public JButton getFindButton() {
        return findButton;
    }

    public JButton getPlayButton() {
        return playButton;
    }

    public JButton getShowAllMultimediaButton() {
        return showAllMultimediaButton;
    }

    public JButton getShowAllGroupButton() {
        return showAllGroupButton;
    }

     
}
