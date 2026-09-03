#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */
void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    
    /* 1. Inicializamos un carrito */
    Carrito c;
    carrito_init(&c);
    
    /* 2. Creamos y agregamos el Pan y la Leche */
    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};
    
    carrito_agregar(&c, pan);
    carrito_agregar(&c, leche);
    
    /* 3. Verificamos el total esperado ($1300) */
    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);
    
    /* 4. Verificamos el precio con 10% de descuento ($1170) */
    int con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, con_descuento);
}
/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

 void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Jabon", 150, 1};

    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);
    carrito_agregar(&c, p);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    int resultado = carrito_agregar(&c, p);
    ASSERT_IGUAL(0, resultado);

    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

/* TODO: escribir test_agregar_hasta_llenar() */

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento();
    test_agregar_hasta_llenar(); 
    RESUMEN();
    return EXIT_CODE();
}

