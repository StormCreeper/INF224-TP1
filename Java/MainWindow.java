import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JToolBar;

import java.awt.event.WindowEvent;

public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    
    private JTextArea textArea;

    public static void main(String[] args) {
        new MainWindow();
    }

    public MainWindow() {
        super("Hello World!");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        add(textArea = new JTextArea(), "Center");

        Action actionExit = new AbstractAction("Exit") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                dispatchEvent(new WindowEvent(MainWindow.this, WindowEvent.WINDOW_CLOSING));
            }
        };

        Action actionButton1 = new AbstractAction("Button 1") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                textArea.append("Button 1 was pressed!\n");
            }
        };

        Action actionButton2 = new AbstractAction("Button 2") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                textArea.append("Button 2 was pressed!\n");
            }
        };

        JPanel panel = new JPanel();
        panel.add(new JButton(actionButton1));
        panel.add(new JButton(actionButton2));
        panel.add(new JButton(actionExit));

        add(panel, "South");

        // Add the menu bar
        JMenuBar menuBar;
        setJMenuBar(menuBar = new JMenuBar());
        JMenu menuFile;
        menuBar.add(menuFile = new JMenu("File"));

        
        menuFile.add(actionButton1);
        menuFile.add(actionButton2);
        menuFile.add(actionExit);

        // Add toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.add(actionButton1);
        toolBar.add(actionButton2);
        toolBar.add(actionExit);

        add(toolBar, "North");

        setVisible(true);
    }
}