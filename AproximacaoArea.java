import java.util.Scanner;
import java.lang.Math.*;

public class AproximacaoArea{
	public static int limInferior;
	public static int limSuperior; 
	public static int qtdReparticoes;
	public static double deltaX;
	public static void DeltaX(int n){
		deltaX = (limSuperior - limInferior);
		//MyIO.println("DeltaX: " + deltaX);
		deltaX /= n;
		//MyIO.println("DeltaX2: " + deltaX);
	}//Operação que define o deltaX, utilizando a função DeltaX = a - l/n (a = limite inferior, l = limite superior, n = quantidade de divisões)
	
	public static double xi(int i){
		double resp = limInferior + (i * deltaX);
		//MyIO.println("Xi: " + resp);
		return resp;
	}//Operação que define o valor de Xi, utilizando a função Xi = a + i * DeltaX (i = ao número da divisão em questão)

	public static double Integral(){
		double resp = 0;
		for(int i = 1; i < qtdReparticoes; i++){
			double aux = xi(i);
			aux = Math.PI;//Alterar a equação que deseja calcular aqui!
			aux *= deltaX;
			resp += aux;	
		}
		return resp;
	}//Operação que realiza o cálculo da integral aproximada utilizando soma de Riemann

	public static Scanner leia = new Scanner(System.in);
	public static void main(String [] args){
		double resp = 0;
		System.out.println("Limite Inferior: ");
		limInferior = leia.nextInt();
		//MyIO.println("limInferior: " + limInferior);
		System.out.println("Limite Superior: ");
		limSuperior = leia.nextInt();
		//MyIO.println("limSuperior: " + limSuperior);
		System.out.println("Quantidade de Repartições: ");
		qtdReparticoes = leia.nextInt();
		//MyIO.println("QtdReparticoes: " + qtdReparticoes);
		DeltaX(qtdReparticoes);	
		resp = Integral();
		//MyIO.println("Resp: " + resp);
		System.out.println("Resultado aproximado da soma com a quantidade de repartições escolhida: " + resp);
		qtdReparticoes = 10000;
		DeltaX(qtdReparticoes);
		resp = Integral();
		System.out.println("Resultado aproximado com 10000 repartições: " + resp);
		qtdReparticoes = 100000;
		DeltaX(qtdReparticoes);
		resp = Integral();
		System.out.println("Resultado aproximado com 100000 repartições: " + resp);
		qtdReparticoes = 1000000;
		DeltaX(qtdReparticoes);
		resp = Integral();
		System.out.println("Resultado aproximado com 1000000 repartições: " + resp);
	}

}
