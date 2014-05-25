package br.blog.carneiro.arduinocidadania;

import javax.swing.JButton;
import org.apache.commons.lang3.StringUtils;
import org.apache.commons.lang3.math.NumberUtils;

/**
 * @author klauder
 */
public class Arduino {

    private ControlePorta arduino;

    /**
     * Construtor da classe Arduino
     */
    public Arduino() {
        arduino = new ControlePorta("COM3", 9600);//Windows - porta e taxa de transmissão
        //arduino = new ControlePorta("/dev/ttyUSB0",9600);//Linux - porta e taxa de transmissão
    }

    /**
     * Envia o comando para a porta serial
     *
     * @param button - Botão que é clicado na interface Java
     */
    public void comunicacaoArduino(JButton button) {
        String comando = button.getActionCommand();
        //se o nome do botão acaba com %, envia o valor antes do %
        //ex: se o botão se chama 40%, envia 40 para o arduino
        if (StringUtils.endsWith(comando, "%")) {
            short valorAenviar = NumberUtils.toShort(StringUtils.chop(comando));
            arduino.enviaDados(valorAenviar);
        } else {
            arduino.close();
            System.out.println(button.getText());//Imprime o nome do botão pressionado
        }
    }
}
