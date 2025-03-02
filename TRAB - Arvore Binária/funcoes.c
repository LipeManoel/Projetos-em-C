//funcoes.c

Tree* createTree(){//funcao que cria uma arvore
  return NULL;
}

int treeIsEmpty(Tree* t){//funcao que verifica se uma arvore e vazia
  return t == NULL;
}

int fatorial(int num){//funcao que faz o fatorial de um numero
    if (num == 0 || num == 1){
        return num;
    } else{
        return num*fatorial(num-1);
    }
}

int analiseComb(int n, int p){//funcao que faz a analise combinatoria
    int fatN = fatorial(n);
    int fatP = fatorial(p);
    int fatNP = fatorial(n-p);

    return fatN/(fatP*fatNP);
}

void insertTree(Tree** t, int num){//funcao que insere um dado na árvore
  	if(*t == NULL){
		*t = (Tree*)malloc(sizeof(Tree));
    	(*t)->left 	= NULL;
    	(*t)->right = NULL;
    	(*t)->num 	= num;
  	}else{
    	if(num < (*t)->num){
      		insertTree(&(*t)->left, num);
    	}
    	if(num > (*t)->num){
      		insertTree(&(*t)->right, num);
    	}
    	if(num == (*t)->num){
    		printf("O número %d já foi inserido na Árvore Binária! \n", num);
		}
  	}
}

int removeTree(Tree** t, int num) {
    if (*t == NULL) return 0;
    if (num < (*t)->num) {
        removeTree(&(*t)->left, num);//buscar a esquerda
    }
    else if (num > (*t)->num) {
        removeTree(&(*t)->right, num);//buscar a direita
    }
    else {//encontrou o no a ser removido

        if ((*t)->left == NULL && (*t)->right == NULL) {//no é uma folha
            free(*t);//libera a memoria do no
            *t = NULL;//aponta para NULL, removendo o no
        }
        else if ((*t)->left == NULL) {//no tem um unico filho
            Tree* temp = *t;
            *t = (*t)->right;  //substitui o no pelo seu filho a direita
            free(temp);  //libera a memoria do no removido
        }
        else if ((*t)->right == NULL) {
            Tree* temp = *t;
            *t = (*t)->left;//substitui o no pelo seu filho a esquerda
            free(temp);//libera a memoria do no removido
        }
        else {//no tem dois filhos
            Tree* temp = MaiorRight(&(*t)->left);//encontra o maior no na subárvore a esquerda (sucessor)
            (*t)->num = temp->num;  //substitui o valor do no pelo maior valor da subárvore a esquerda
            removeTree(&(*t)->left, temp->num);//remove o sucessor
        }
        return 1;
    }
}

int isInTree(Tree* t, int num){//funcao que verifica se um elemento pertence ou não à árvore
	if(treeIsEmpty(t)) {
    	return 0;
  	}
  	return t->num==num || isInTree(t->left, num) || isInTree(t->right, num);
}

int maior(int a, int b){//funcao que retorna o maior numero do parametro
    if(a > b)
        return a;
    else
        return b;
}

int altura(Tree *t){//funcao que retorna a altura da arvore
   if((t == NULL) || (t->left == NULL && t->right == NULL))
       return 0;
   else
       return 1 + maior(altura(t->left), altura(t->right));
}

Tree *MaiorRight(Tree **t)//funcao que pega o maior numero a direita
{
    if ((*t)->right != NULL) {
        return MaiorRight(&(*t)->right);
    } else {
        Tree *aux = *t;
        if ((*t)->left != NULL) {
            *t = (*t)->left;
        } else {
            *t = NULL;
        }
        return aux;
    }
}

Tree *MenorLeft(Tree **t)//funcao que pega o menor numero a esquerda
{
    if((*t)->left != NULL){
       return MenorLeft(&(*t)->left);
    }else{
        Tree *aux = *t;
        if((*t)->right != NULL) {
          *t = (*t)->right;
        }else{
          *t = NULL;
        }
        return aux;
    }
}

int contarFolhas(Tree* t) {//funcao que conta as folhas da arvore
    if (t == NULL) {
        return 0; //se a arvore estiver vazia, retorna 0
    }
    if (t->left == NULL && t->right == NULL) {//se o no for uma folha
        return 1;
    }
    //caso contrario, soma as folhas das subarvores
    return contarFolhas(t->left) + contarFolhas(t->right);
}

int contarNos(Tree *t) {//funcao que conta os nos da arvore
    if (t == NULL) {
        return 0; //se a árvore estiver vazia, retorna 0
    }
    return 1 + contarNos(t->left) + contarNos(t->right); //conta o no atual + nos das subárvores
}
