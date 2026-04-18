using System;
using System.Collections.Generic;

public class Node {
    public int Key { get; set; }
    public Node? Left { get; set; }
    public Node? Right { get; set; }

    public Node(int key) {
        Key = key;
        Left = null;
        Right = null;
    }
}

public class BST {

    public Node? Root;

    /* 
        Para fazer esse código utilizei o que você ensinou na aula de ?
        significar que pode ser null. O inserir e o resto das funções você havia 
        passado em sala de aula então fiz baseado nisso.
    */
    
    // Inserir valor
    public void Insert(int value) {
        Root = InsertRec(Root, value);
    }

    // Função recursiva de inserção
    private Node InsertRec(Node? current, int value) {
        
         // Se chegou em um lugar vazio, cria o nó
        if (current == null) {
            return new Node(value);
        }
        
        // Se o valor é menor, vai para esquerda
        if (value < current.Key) {
            current.Left = InsertRec(current.Left, value);
        }
        
        // Se o valor é maior, vai para direita
        else if (value > current.Key) {
            current.Right = InsertRec(current.Right, value);
        }

        return current;
    }

    // Buscar valor
    public Node? Search(int value) {
        return SearchRec(Root, value);
    }
    
    // Função recursiva de busca
    private Node? SearchRec(Node? current, int value) {
        
        // Caso base: se raiz é nula ou se o valor é igual a raiz
        if (current == null || current.Key == value) {
            return current;
        }
        
        // Se for menor, busca na esquerda
        if (value < current.Key) {
            return SearchRec(current.Left, value);
        }
        
        // Se for maior, busca na direita
        return SearchRec(current.Right, value);
    }

    // Máximo iterativo
    public Node? MaximoIterativo() {
        Node? atual = Root;

        if (atual == null) return null;

        while (atual.Right != null) {
            atual = atual.Right;
        }

        return atual;
    }

    // Máximo recursivo
    public Node? MaximoRecursivo() {
        return MaxRec(Root);
    }

    private Node? MaxRec(Node? atual) {
        if (atual == null) return null;

        if (atual.Right == null) return atual;

        return MaxRec(atual.Right);
    }

    // Mínimo Iterativo
    public Node? MinimoIterativo() {
        Node? atual = Root;

        if (atual == null) return null;

        while (atual.Left != null) {
            atual = atual.Left;
        }

        return atual;
    }
    
    // Mínimo Recursivo
    public Node? MinimoRecursivo() {
        return MinRec(Root);
    }

    private Node? MinRec(Node? atual) {
        if (atual == null) return null;

        if (atual.Left == null) return atual;

        return MinRec(atual.Left);
    }

    // In order Recursivo
    public void PrintInOrder() {
        InOrderRecursivo(Root);
        Console.WriteLine();
    }

    private void InOrderRecursivo(Node? atual) {
        if (atual == null) return;

        InOrderRecursivo(atual.Left);
        Console.Write(atual.Key + " ");
        InOrderRecursivo(atual.Right);
    }

    // In order Iterativo
    public void PrintInOrderIterativo() {
        Stack<Node> stack = new Stack<Node>();
        Node? atual = Root;

        while (atual != null || stack.Count > 0) {

            while (atual != null) {
                stack.Push(atual);
                atual = atual.Left;
            }

            atual = stack.Pop();
            Console.Write(atual.Key + " ");

            atual = atual.Right;
        }

        Console.WriteLine();
    }

    // Fiz o coolPrint recursivo pois é mais fácil
    public void CoolPrint() {
        CoolPrintRec(Root, 0);
    }

    /*Aqui eu passei o nó podendo ser null e o nível representa a profundidade,
        raiz sendo 0, filhos da raiz 1, netos 2 e assim vai. Se o nó for nulo 
        retorna ele mesmo, e aí tem um for que percorre a arvore por níveis 
        indo da raiz até a folha e imprime 4 espaços para cada nível, se o nível
        for 0 não cria espaço, se for 1 cria um espaço, e assim sucessivamente
        aí printa o número depois dos espaços com o node.key. Aí depois ele 
        vai para o filho esquerdo, vai para o filho direito e aumenta o nível,
        fiz nível + 1 para ir descendo na profundidade
    */
    
    private void CoolPrintRec(Node? node, int nivel) {
        if (node == null) return;

        for (int i = 0; i < nivel; i++) {
            Console.Write("    ");
        }

        Console.WriteLine(node.Key);

        CoolPrintRec(node.Left, nivel + 1);
        CoolPrintRec(node.Right, nivel + 1);
    }
}


public class Program {
    public static void Main(string[] args) {

        BST bst = new BST();

        bst.Insert(15);
        bst.Insert(10);
        bst.Insert(8);
        bst.Insert(12);
        bst.Insert(20);
        bst.Insert(21);

        Console.WriteLine("In-order recursivo:");
        bst.PrintInOrder();

        Console.WriteLine("\nIn-order iterativo:");
        bst.PrintInOrderIterativo();

        Console.WriteLine("\nMenor valor:");
        Console.WriteLine(bst.MinimoIterativo()?.Key);

        Console.WriteLine("\nMaior valor:");
        Console.WriteLine(bst.MaximoIterativo()?.Key);

        Console.WriteLine("\nVisualização da árvore:");
        bst.CoolPrint();
    }
}