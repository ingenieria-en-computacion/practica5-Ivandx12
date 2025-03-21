#include "stack.h"

/**
 * Crea una nueva pila vacía y la devuelve.
 * 
 * @return Un auntador a la nueva pila creada. Si la creación falla, devuelve NULL.
 * @details Esta función asigna memoria dinámicamente para una nueva pila utilizando `malloc`.
 *          Si la asignación de memoria falla, la función devuelve NULL. La pila creada
 *          está vacía y top apunta a NULL
 */
Stack *stack_create(){
    Stack *s = (Stack *)malloc(sizeof(Stack));
    if (!s) return NULL;
    s->top = NULL;
    return s;
}

/**
 * Inserta un elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila donde se insertará el elemento.
 * @param d Dato que se insertará en la pila.
 * @details Esta función añade el dato `d` en la parte superior de la pila. Si la pila está llena
 *          o el puntero `s` es NULL, la función no realiza ninguna operación.
 */
void stack_push(Stack* s, Data d){
    if (!s) return;
    Node *new = new_node(d);
    if (!new) return;
    new->next = s->top;
    s->top = new;
}

/**
 * Elimina y devuelve el elemento en la parte superior de la pila.
 * 
 * @param s Auntador a la pila de la cual se eliminará el elemento.
 * @return El dato que estaba en la parte superior de la pila. Si la pila está vacía o el puntero
 *         `s` es NULL, devuelve un valor que indica error (por ejemplo, -1 o un valor predeterminado).
 * @details Esta función elimina el elemento en la parte superior de la pila y lo devuelve.
 *          Si la pila está vacía, no se realiza ninguna operación y se devuelve un valor de error.
 */
Data stack_pop(Stack* s){
    if (!s || !s->top) return -1;
    Node *temp = s->top;
    Data d = temp->data;
    s->top = temp->next;
    free(temp);
    return d;
}

/**
 * Verifica si la pila está vacía.
 * 
 * @param s Auntador a la pila que se desea verificar.
 * @return 1 si la pila está vacía, 0 si no lo está. Si el puntero `s` es NULL, devuelve -1.
 * @details Esta función comprueba si la pila no contiene elementos. Es útil para evitar operaciones
 *          como `stack_pop` en una pila vacía.
 */
bool stack_is_empty(Stack* s){
    return (!s || s->top == NULL);
}

/**
 * Vacía la pila, eliminando todos sus elementos.
 * 
 * @param s Auntador a la pila que se desea vaciar.
 * @details Esta función elimina todos los elementos de la pila, dejándola vacía.
 *          Si el puntero `s` es NULL, la función no realiza ninguna operación.
 *          La memoria de los elementos eliminados se libera adecuadamente.
 */
void stack_empty(Stack* s){
    if (!s) return;
    while (!stack_is_empty(s)) {
        stack_pop(s);
    }
}

/**
 * Elimina la pila y libera la memoria asociada a ella.
 * 
 * @param s Auntador a la pila que se desea eliminar.
 * @details Esta función libera la memoria asignada dinámicamente para la pila y todos sus elementos
 *          utilizando `free`. Si el puntero pasado es NULL, la función no realiza ninguna operación.
 *          Es responsabilidad del llamante asegurarse de que la pila ya no se utiliza después
 *          de ser eliminada.
 */
void stack_delete(Stack *s){
    if (!s) return;
    stack_empty(s);
    free(s);
}


/**
 * Imprime los elementos de la pila.
 * 
 * @param s Auntador a la pila que se desea imprimir.
 * @details Esta función imprime los elementos de la pila en orden, desde la parte superior
 *          hasta la base. Si la pila está vacía o el puntero `s` es NULL, la función imprime
 *          un mensaje indicando que la pila está vacía o es inválida. La salida se dirige a
 *          la salida estándar (stdout).
 */
void stack_print(Stack *s){
    if (!s || !s->top) {
        printf("Pila vacía\n");
        return;
    }
    Node *temp = s->top;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}