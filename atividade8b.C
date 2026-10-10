#include "raylib.h"
#include "entidade.h"
#include <stddef.h>

int main(void) {
    const int larguraTela = 800;
    const int alturaTela = 450;
    InitWindow(larguraTela, alturaTela, "Exercício 8b - Reuso de Módulo");
    SetTargetFPS(60);

    Entidade *jogador = entidadeCriar(ENTIDADE_JOGADOR, (Vector2){200, 225});
    Entidade *inimigo = entidadeCriar(ENTIDADE_INIMIGO, (Vector2){400, 225});
    Entidade *item    = entidadeCriar(ENTIDADE_ITEM,    (Vector2){600, 225});

    while (!WindowShouldClose()) {
        
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("Demonstração de Reuso do Módulo Entidade", 10, 10, 20, DARKGRAY);

            if (jogador != NULL) entidadeDesenhar(jogador);
            if (inimigo != NULL) entidadeDesenhar(inimigo);
            if (item != NULL)    entidadeDesenhar(item);

        EndDrawing();
    }

    if (jogador) free(jogador);
    if (inimigo) free(inimigo);
    if (item)    free(item);

    CloseWindow();
    return 0;
}