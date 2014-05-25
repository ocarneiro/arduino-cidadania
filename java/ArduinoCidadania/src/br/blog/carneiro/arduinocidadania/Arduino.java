package br.blog.carneiro.arduinocidadania;

import javax.swing.JButton;

/**
 * @author klauder
 */
public class Arduino {
  private ControlePorta arduino;
  
  /**
   * Construtor da classe Arduino
   */
  public Arduino(){
      arduino = new ControlePorta("COM3",9600);//Windows - porta e taxa de transmissão
      //arduino = new ControlePorta("/dev/ttyUSB0",9600);//Linux - porta e taxa de transmissão
  }    

  /**
   * Envia o comando para a porta serial
   * @param button - Botão que é clicado na interface Java
   */
  public void comunicacaoArduino(JButton button) {        
    if("Acender".equals(button.getActionCommand())){
      arduino.enviaDados((short)100);
      System.out.println(button.getText());//Imprime o nome do botão pressionado
    }
    else if("Apagar".equals(button.getActionCommand())){
      arduino.enviaDados((short)0);
      System.out.println(button.getText());
    }
    else{
      arduino.close();
      System.out.println(button.getText());//Imprime o nome do botão pressionado
    }
  }
}