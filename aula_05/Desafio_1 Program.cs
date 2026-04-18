// Nó da árvore
public class Node {
    public int Key { get; set; }
    public Node Left { get; set; }
    public Node Right { get; set; }
    
    // Construtor
    public Node(int key) {
        this.Key = key;
    }
}

// BST é Binary Search Tree
public class BST {
     public Node Root; // raiz da árvore

    // Inserir valor
    public void Insert(int value) {
        Root = InsertRec(Root, value);
    }

    // Função recursiva de inserção
    private Node InsertRec(Node current, int value) {

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
    public Node Search(int value) {
        return SearchRec(Root, value);
    }

    // Função recursiva de busca
    private Node SearchRec(Node current, int value) {

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
    
}