typedef struct arvore *Arvore;

Arvore inicializar();

Arvore destruir(Arvore a);

Arvore inserirAbb(Arvore a, int chave, void* obj, int sizeObj);

Arvore removerAbb(Arvore a, int chave, int sizeObj);

int existe(Arvore a, int chave);

int buscar(Arvore a, int chave, void* obj, int sizeObj);

void imprimirLargura(Arvore a);
