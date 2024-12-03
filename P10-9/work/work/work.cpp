#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* card structure definition */
typedef struct card {
    const char* face; /* define pointer face */   //使用const 只是因為警告 理論上是可以的
    const char* suit; /* define pointer suit */
}Card; /* end structure card */

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]);
void shuffle(Card* const wDeck);
void deal(const Card* const wDeck);


int main(void)
{
    Card deck[52];

    const char* face[] = { "Ace","Deuce","Three","Four","Five","Six","Seven","Eight","Nine","Ten","Jack","Queen","King" };
    const char* suit[] = { "Hearts","Diamonds","Clubs","Spades" };

    srand(time(NULL));

    fillDeck(deck, face, suit);
    shuffle(deck);
    deal(deck);

    return 0; /* indicates successful termination */
} /* end main */

void fillDeck(Card* const wDeck, const char* wFace[], const char* wSuit[]) {     //分配函數
    int i;
    for (i = 0;i <= 51;i++) {
        wDeck[i].face = wFace[i % 13];   // 給數字
        wDeck[i].suit = wSuit[i / 13];   // 給符號
    }
};

void shuffle(Card* const wDeck) {     //隨機數交換陣列中的卡片
    int i;
    int j;
    Card temp;
    for (i = 0;i <= 51;i++) {
        j = rand() % 52;
        temp = wDeck[i];
        wDeck[i] = wDeck[j];
        wDeck[j] = temp;
    }
};

void deal(const Card* const wDeck) {  //印出
    int i;
    for (i = 0;i <= 51;i++) {
        printf("%5s of %-8s%s", wDeck[i].face, wDeck[i].suit, (i + 1) % 4 ? " " : "\n");      // 數字,符號,沒到四空格否則換行
    }
};
