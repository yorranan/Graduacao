// Definição dos nós de um ABB
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Responsável pelo menu
void view_menu()
{
	printf("\n");
	printf("1 - Inserir elementos\n");
	printf("2 - Percuso em largura\n");
	printf("3 - Sair\n");
}

void BFS(struct Node *root)
{
    // Cria uma fila para armazenar os nós que vão ser visitados
    struct Node **queue = (struct Node **) malloc (sizeof(struct Node *));
    int head = 0, tail = 0;

    // Insere o nó pai na fila
    queue[tail] = root;
    tail++;

	/*
	 Até que a fila não esteja vazia, o trecho abaixo retira e insere o próximo nó e seus filhos
	 na fila
	*/ 
    while (head < tail)
    {
        struct Node *current = queue[head];
        head++;

        printf("%d ", current->data);

        if (current->left != NULL)
        {
            // Usando realocação de memória na fila para não perder dados
            queue = (struct Node **)realloc(queue, sizeof(struct Node *) * (tail + 1));
            // Adicionando uma nova posição a esquerda
            queue[tail] = current->left;
            tail++;
        }
        if (current->right != NULL)
        {
            queue = (struct Node **)realloc(queue, sizeof(struct Node *) * (tail + 1));
            queue[tail] = current->right;
            tail++;
        }
    }

    free(queue);
}

void insert(struct Node **root, int data)
{
    // se a árvore estiver vazia, insere o novo elemento como raiz
    if (*root == NULL)
    {
        *root = (struct Node *)malloc(sizeof(struct Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        return;
    }

    // se o novo elemento for menor que o valor do nó atual, insere na subárvore esquerda
    if (data < (*root)->data)
    {
        insert(&((*root)->left), data);
    }
    // se o novo elemento for maior que o valor do nó atual, insere na subárvore direita
    else
    {
        insert(&((*root)->right), data);
    }
}