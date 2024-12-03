#include <stdio.h>

/* card structure definition */
struct card {
   const char *face; /* define pointer face */   //使用const 只是因為警告 理論上是可以的
   const char *suit; /* define pointer suit */
}; /* end structure card */

int main(void)
{
    struct card aCard; /* define one struct card variable */
    struct card *cardPtr; /* define a pointer to a struct card */

    /* place strings into aCard */
    aCard.face = "Ace";
    aCard.suit = "Spades";

    cardPtr = &aCard; /* assign address of aCard to cardPtr */

    printf("%s%s%s\n%s%s%s\n%s%s%s\n",aCard.face, " of ", aCard.suit, cardPtr->face, " of ",cardPtr->suit, (*cardPtr).face, " of ", (*cardPtr).suit);  //三種寫法都可以

    return 0; /* indicates successful termination */
} /* end main */
