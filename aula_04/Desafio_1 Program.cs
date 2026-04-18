using System;
using System.Collections.Generic;

/* 
   Como o desafio havia proposto criei uma classe base pokemon e uma classe 
   treinador e fiz as subclasses como heranças de pokemon, sendo pokemon fogo, 
   pokemon agua e pokemon grama, fiz o construtor da classe pokemon deixando 
   ele público, fiz o método exibir status, o método atacar, para as subclasses
   de cada pokemon eu fiz com os danos propostos e fiz a classe treinador com
   os métodos requisitados e fiz a simulação de batalha com dois treinadores
   sendo cada um com 2 pokemons. para isso usei o new para criar diferentes
   treinadores e diferentes pokemons. Usei sobrescrita para alterar as subclasses
   que tem diferenças da classe base e usei um while para fazer a batalha.
*/

class Pokemon
{
    public string Nome;
    public string Tipo;
    public int Vida;
    public int Ataque;
    public int Defesa;

    public Pokemon(string nome, string tipo, int vida, int ataque, int defesa)
    {
        Nome = nome;
        Tipo = tipo;
        Vida = vida;
        Ataque = ataque;
        Defesa = defesa;
    }

    public void ExibirStatus()
    {
        Console.WriteLine($"{Nome} ({Tipo}) - Vida: {Vida}, Ataque: {Ataque}, Defesa: {Defesa}");
    }

    public virtual void Atacar(Pokemon alvo)
    {
        int dano = Ataque - alvo.Defesa;
        if (dano < 1) dano = 1;

        alvo.Vida -= dano;

        if (alvo.Vida < 0) alvo.Vida = 0;

        Console.WriteLine($"{Nome} atacou {alvo.Nome} e causou {dano} de dano.");
        Console.WriteLine($"{alvo.Nome} agora está com {alvo.Vida} de vida.\n");
    }
}

class PokemonFogo : Pokemon
{
    public PokemonFogo(string nome, int vida, int ataque, int defesa)
        : base(nome, "Fogo", vida, ataque, defesa) { }

    public override void Atacar(Pokemon alvo)
    {
        int dano = (Ataque - alvo.Defesa) + 2;
        if (dano < 1) dano = 1;

        alvo.Vida -= dano;
        if (alvo.Vida < 0) alvo.Vida = 0;

        Console.WriteLine($"{Nome} (Fogo) atacou {alvo.Nome} e causou {dano} de dano!");
    }
}

class PokemonAgua : Pokemon
{
    public PokemonAgua(string nome, int vida, int ataque, int defesa)
        : base(nome, "Água", vida, ataque, defesa) { }

    public override void Atacar(Pokemon alvo)
    {
        int dano = Ataque - alvo.Defesa;
        if (dano < 1) dano = 1;

        alvo.Vida -= dano;

        Vida += 2; 

        Console.WriteLine($"{Nome} (Água) atacou {alvo.Nome} e causou {dano} de dano.");
        Console.WriteLine($"{Nome} recuperou 2 de vida!");
    }
}

class PokemonGrama : Pokemon
{
    Random rand = new Random();

    public PokemonGrama(string nome, int vida, int ataque, int defesa)
        : base(nome, "Grama", vida, ataque, defesa) { }

    public override void Atacar(Pokemon alvo)
    {
        int dano = Ataque - alvo.Defesa;
        if (dano < 1) dano = 1;

      
        if (rand.Next(100) < 20)
        {
            dano *= 2;
            Console.WriteLine("ATAQUE CRÍTICO!");
        }

        alvo.Vida -= dano;

        Console.WriteLine($"{Nome} (Grama) atacou {alvo.Nome} e causou {dano} de dano.");
    }
}

class Treinador
{
    public string Nome;
    public List<Pokemon> Pokemons = new List<Pokemon>();

    public Treinador(string nome)
    {
        Nome = nome;
    }

    public void AdicionarPokemon(Pokemon p)
    {
        Pokemons.Add(p);
    }

    public void ListarPokemons()
    {
        for (int i = 0; i < Pokemons.Count; i++)
        {
            Console.WriteLine($"{i} - {Pokemons[i].Nome}");
        }
    }

    public Pokemon EscolherPokemon(int indice)
    {
        return Pokemons[indice];
    }
}

class Program
{
    static void Main()
    {
        Treinador ash = new Treinador("Ash");
        Treinador misty = new Treinador("Misty");

        ash.AdicionarPokemon(new PokemonFogo("Charmander", 20, 6, 2));
        ash.AdicionarPokemon(new PokemonGrama("Bulbasaur", 22, 5, 3));

        misty.AdicionarPokemon(new PokemonAgua("Squirtle", 25, 5, 3));
        misty.AdicionarPokemon(new PokemonGrama("Oddish", 20, 4, 2));

        Pokemon p1 = ash.EscolherPokemon(0);
        Pokemon p2 = misty.EscolherPokemon(0);

        Console.WriteLine($"{ash.Nome} escolheu {p1.Nome}!");
        Console.WriteLine($"{misty.Nome} escolheu {p2.Nome}!\n");


        while (p1.Vida > 0 && p2.Vida > 0)
        {
            p1.Atacar(p2);
            if (p2.Vida <= 0) break;

            p2.Atacar(p1);
        }

        if (p1.Vida > 0)
            Console.WriteLine($"{p1.Nome} venceu!");
        else
            Console.WriteLine($"{p2.Nome} venceu!");
    }
}