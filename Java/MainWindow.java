import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;
import javax.swing.JToolBar;

import java.awt.event.WindowEvent;


public class MainWindow extends JFrame {
    private static final long serialVersionUID = 1L;
    
    private JTextArea textArea;

    // Network variables 

    public static void main(String[] args) {
        MainWindow window = new MainWindow();
        Client client = null;

        try {
			client = new Client(Client.DEFAULT_HOST, Client.DEFAULT_PORT);
		} catch (Exception e) {
			window.writeLine("Client: Couldn't connect to " + Client.DEFAULT_HOST + ":" + Client.DEFAULT_PORT);
            client = null;
		}

        if (client != null) {
            window.writeLine("Client connected to " + Client.DEFAULT_HOST + ":" + Client.DEFAULT_PORT);
        }
    }

    public MainWindow() {
        super("Hello World!");
        setSize(500, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        initUI();

        setVisible(true);
    }

    private void initUI() {
        add(textArea = new JTextArea(), "Center");

        Action actionExit = new AbstractAction("Exit") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                dispatchEvent(new WindowEvent(MainWindow.this, WindowEvent.WINDOW_CLOSING));
            }
        };
        Action actionDisplay = new AbstractAction("Display info") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                writeLine("Displaying info");
            }
        };
        Action actionPlay = new AbstractAction("Play") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                writeLine("Playing");
            }
        };
        Action actionList = new AbstractAction("List") {
            @Override
            public void actionPerformed(java.awt.event.ActionEvent e) {
                writeLine("Listing");
            }
        };

        // Add the button panel
        // Two buttons with a text field and one exit button
        JPanel panel = new JPanel();
        JPanel panelDisplay = new JPanel();
        JPanel panelPlay = new JPanel();
        // text field is above the button
        panelDisplay.setLayout(new java.awt.GridLayout(2, 1));
        panelPlay.setLayout(new java.awt.GridLayout(2, 1));

        panelDisplay.add(new JTextField());
        panelPlay.add(new JTextField());
        
        panelDisplay.add(new JButton(actionDisplay));
        panelPlay.add(new JButton(actionPlay));
        panel.add(panelDisplay);
        panel.add(panelPlay);
        panel.add(new JButton(actionExit));

        add(panel, "South");

        // Add the menu bar
        JMenuBar menuBar;
        JMenu menuFile;
        
        setJMenuBar(menuBar = new JMenuBar());
        menuBar.add(menuFile = new JMenu("File"));
        
        menuFile.add(actionList);
        menuFile.add(actionExit);

        // Add toolbar
        JToolBar toolBar = new JToolBar();
        toolBar.add(panelPlay);
        toolBar.add(panelDisplay);
        toolBar.add(actionList);
        toolBar.add(actionExit);

        add(toolBar, "North");
    }

    public void writeLine(String line) {
        textArea.append(line + "\n");
    }
}