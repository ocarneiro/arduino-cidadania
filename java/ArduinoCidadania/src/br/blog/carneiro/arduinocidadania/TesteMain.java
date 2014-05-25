/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package br.blog.carneiro.arduinocidadania;

/**
 *
 * @author Otávio
 */
public class TesteMain {
    public static void main (String[] a) {
        int entrada = -400;
        int centena = entrada / 100;
        int dezena = (entrada-centena*100) /10;
        int inteiro = entrada-centena*100-dezena*10;
        System.out.println("c" + centena + "d" + dezena + "i" + inteiro);
    }
}
