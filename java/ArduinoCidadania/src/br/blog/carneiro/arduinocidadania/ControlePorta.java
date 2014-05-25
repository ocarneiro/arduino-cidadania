package br.blog.carneiro.arduinocidadania;

import gnu.io.CommPortIdentifier;
import gnu.io.NoSuchPortException;
import gnu.io.SerialPort;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JOptionPane;

public class ControlePorta {

    private OutputStream serialOut;
    private InputStream serialIn;
    private int taxa;
    private String portaCOM;

    /**
     * Construtor da classe ControlePorta
     *
     * @param portaCOM - Porta COM que será utilizada para enviar os dados para
     * o arduino
     * @param taxa - Taxa de transferência da porta serial geralmente é 9600
     */
    public ControlePorta(String portaCOM, int taxa) {
        this.portaCOM = portaCOM;
        this.taxa = taxa;
        this.initialize();
    }

    /**
     * Médoto que verifica se a comunicação com a porta serial está ok
     */
    private void initialize() {
        try {
            //Define uma variável portId do tipo CommPortIdentifier para realizar a comunicação serial
            CommPortIdentifier portId = null;
            try {
                //Tenta verificar se a porta COM informada existe
                portId = CommPortIdentifier.getPortIdentifier(this.portaCOM);
            } catch (NoSuchPortException npe) {
                //Caso a porta COM não exista será exibido um erro 
                JOptionPane.showMessageDialog(null, "Porta COM não encontrada.",
                        "Porta COM", JOptionPane.PLAIN_MESSAGE);
            }
            //Abre a porta COM 
            SerialPort port = (SerialPort) portId.open("Comunicação serial", this.taxa);
            serialOut = port.getOutputStream();
            serialIn = port.getInputStream();
            port.setSerialPortParams(this.taxa, //taxa de transferência da porta serial 
                    SerialPort.DATABITS_8, //taxa de 10 bits 8 (envio)
                    SerialPort.STOPBITS_1, //taxa de 10 bits 1 (recebimento)
                    SerialPort.PARITY_NONE); //receber e enviar dados
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    /**
     * Método que fecha a comunicação com a porta serial
     */
    public void close() {
        try {
            serialOut.close();
        } catch (IOException e) {
            JOptionPane.showMessageDialog(null, "Não foi possível fechar porta COM.",
                    "Fechar porta COM", JOptionPane.PLAIN_MESSAGE);
        }
    }

    /**
     * @param opcao - Valor a ser enviado pela porta serial
     */
    public void enviaDados(short valor) {
        
        try {
            short valorConsiderado = valor;
            if (valor > 999) {
                valorConsiderado = 999;
            } else if (valor < 0) {
                valorConsiderado = 0;
            }
            int centena = (valorConsiderado / 100);
            int dezena = ((valorConsiderado - centena * 100) / 10);
            int inteiro = (valorConsiderado - centena * 100 - dezena * 10);

            String valorString = "" + centena + dezena + inteiro;
            //int valorFinal = centena * 100 + dezena * 10 + inteiro;
            System.out.println("Mandei: " + valorString);
            
            serialOut.write(valorString.getBytes());

            //serialOut.write((""+centena).getBytes());
            //serialOut.write(dezena);
            //serialOut.write(inteiro);
            //serialOut.flush();

            System.out.println ("Recebi: " + serialIn.available() + " bytes");
            while (serialIn.available()>0) {
                System.out.print((char)serialIn.read());
            }
            System.out.println(".");
            

        } catch (IOException ex) {
            JOptionPane.showMessageDialog(null, "Não foi possível enviar o dado. ",
                    "Enviar dados", JOptionPane.PLAIN_MESSAGE);
        }
    }
}
