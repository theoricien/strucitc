#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

void test_get (void);
void test_pop (void);
void test_push (void);

int
main (void)
{
    void (*tests[])(void) = {
        test_push,
        test_get,
        test_pop
    };

    for (size_t i = 0; i < sizeof(tests) / sizeof(*(tests)); i++)
        tests[i]();

    return EXIT_SUCCESS;
}

void
test_push (void)
{
    struct stack_t *stk;

    stk = init_stack();
    stk->push(stk, "3");
    stk->push(stk, "4");
    stk->push(stk, "+");

    assert(stk->size == 3, "test_push: stk->size");

    assert(!strcmp(stk->top->curr->value, "+"), "test_push: !strcmp(stk->top->curr->value, \"+\")");
    assert(!strcmp(stk->top->prev->curr->value, "4"), "test_push: !strcmp(stk->top->prev->curr->value, \"4\")");
    assert(!strcmp(stk->top->prev->prev->curr->value, "3"), "test_push: !stk->top->prev->prev->curr->value, \"3\")");

    assert(stk->top->curr->addr == 2, "test_push: stk->top->curr->addr == 2");
    assert(stk->top->prev->curr->addr == 1, "test_push: stk->top->prev->curr->addr");
    assert(stk->top->prev->prev->curr->addr == 0, "test_push: stk->top->prev->prev->curr->addr == 0");
}

void
test_get (void)
{
    struct stack_t *stk;
    struct mcell_t *after;

    stk = init_stack();
    stk->push(stk, "3");
    stk->push(stk, "4");
    stk->push(stk, "+");

    after = stk->get(stk, 0);

    assert(stk->size == 3, "test_get: stk->size == 3");
    assert(!strcmp(after->value, "3"), "test_get: !strcmp(after->value, \"3\")");
    assert(after->addr == 0, "test_get: after->addr == 1");

    after = stk->get(stk, 1);

    assert(stk->size == 3, "test_get: stk->size == 3");
    assert(!strcmp(after->value, "4"), "test_get: !strcmp(after->value, \"4\")");
    assert(after->addr == 1, "test_get: after->addr == 1");

    after = stk->get(stk, 2);

    assert(stk->size == 3, "test_get: stk->size == 3");
    assert(!strcmp(after->value, "+"), "test_get: !strcmp(after->value, \"+\")");
    assert(after->addr == 2, "test_get: after->addr == 2");
}

void
test_pop (void)
{
    struct stack_t *stk;
    struct mcell_t *after;

    stk = init_stack();
    stk->push(stk, "3");
    stk->push(stk, "4");
    stk->push(stk, "+");

    /* Init test */
    assert(stk->size == 3, "test_pop: stk->size");

    assert(!strcmp(stk->top->curr->value, "+"), "test_pop: !strcmp(stk->top->curr->value, \"+\")");
    assert(!strcmp(stk->top->prev->curr->value, "4"), "test_pop: !strcmp(stk->top->prev->curr->value, \"4\")");
    assert(!strcmp(stk->top->prev->prev->curr->value, "3"), "test_pop: !stk->top->prev->prev->curr->value, \"3\")");

    assert(stk->top->curr->addr == 2, "test_pop: stk->top->curr->addr == 2");
    assert(stk->top->prev->curr->addr == 1, "test_pop: stk->top->prev->curr->addr == 1");
    assert(stk->top->prev->prev->curr->addr == 0, "test_pop: stk->top->prev->prev->curr->addr == 0");

    /* POP */
    after = stk->pop(stk);

    assert(stk->size == 2, "test_pop: stk->size");

    assert(!strcmp(stk->top->curr->value, "4"), "test_pop: !strcmp(stk->top->curr->value, \"4\")");
    assert(!strcmp(stk->top->prev->curr->value, "3"), "test_pop: !strcmp(stk->top->prev->curr->value, \"3\")");

    assert(stk->top->curr->addr == 1, "test_pop: stk->top->curr->addr == 1");
    assert(stk->top->prev->curr->addr == 0, "test_pop: stk->top->prev->curr->addr == 0");

    assert(!strcmp(after->value, "+"), "test_pop: !strcmp(after->value, \"+\")");
    assert(after->addr == 2, "test_pop: after->addr == 2");

    /* POP */
    after = stk->pop(stk);

    assert(stk->size == 1, "test_pop: stk->size");
    assert(!strcmp(stk->top->curr->value, "3"), "test_pop: !strcmp(stk->top->curr->value, \"3\")");
    assert(stk->top->curr->addr == 0, "test_pop: stk->top->curr->addr == 0");

    assert(!strcmp(after->value, "4"), "test_pop: !strcmp(after->value, \"4\")");
    assert(after->addr == 1, "test_pop: after->addr == 1");

    /* POP */
    after = stk->pop(stk);

    assert(stk->size == 0, "test_pop: stk->size");

    assert(!strcmp(after->value, "3"), "test_pop: !strcmp(after->value, \"3\")");
    assert(after->addr == 0, "test_pop: after->addr == 0");
}
