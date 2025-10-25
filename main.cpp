#include <iostream> // For input/output

/**
 * @brief Prints ASCII characters and their corresponding codes from 0 to 240.
 *        Each line shows the character and its ASCII value.
 */
void printchar()
{   
    // Print table header
    std::cout << "ASCII Table\n";
    std::cout << "-----------------------------\n";
    std::cout << "Char\t|\tASCII\n";
    std::cout << "-----------------------------\n";

    // Loop through ASCII codes from 0 to 240
    for (int i = 0; i <= 240; ++i) {
        std::cout << " Char " << char(i) << "\t|\t ASCII  " << i << std::endl;
    }
}

/**
 * @brief Main function that starts the program.
 */
int main() {
    printchar(); // Call the function to print the ASCII table
    return 0;
}

// ASCII Table
// -----------------------------
// Char    |       ASCII
// -----------------------------
//  Char   |        ASCII  0
//  Char ☺ |        ASCII  1
//  Char ☻ |        ASCII  2
//  Char ♥ |        ASCII  3
//  Char ♦ |        ASCII  4
//  Char ♣ |        ASCII  5
//  Char ♠ |        ASCII  6
//  Char   |        ASCII  7
//  Char   |        ASCII  8
//  Char           |        ASCII  9
//  Char
//         |        ASCII  10
//  Char ♂ |        ASCII  11
//  Char ♀ |        ASCII  12
//  Char   |        ASCII  13
//  Char ♫ |        ASCII  14
//  Char ☼ |        ASCII  15
//  Char ► |        ASCII  16
//  Char ◄ |        ASCII  17
//  Char ↕ |        ASCII  18
//  Char ‼ |        ASCII  19
//  Char ¶ |        ASCII  20
//  Char § |        ASCII  21
//  Char ▬ |        ASCII  22
//  Char ↨ |        ASCII  23
//  Char ↑ |        ASCII  24
//  Char ↓ |        ASCII  25
//  Char → |        ASCII  26
//  Char            ASCII  27
//  Char ∟ |        ASCII  28
//  Char ↔ |        ASCII  29
//  Char ▲ |        ASCII  30
//  Char ▼ |        ASCII  31
//  Char   |        ASCII  32
//  Char ! |        ASCII  33
//  Char " |        ASCII  34
//  Char # |        ASCII  35
//  Char $ |        ASCII  36
//  Char % |        ASCII  37
//  Char & |        ASCII  38
//  Char ' |        ASCII  39
//  Char ( |        ASCII  40
//  Char ) |        ASCII  41
//  Char * |        ASCII  42
//  Char + |        ASCII  43
//  Char , |        ASCII  44
//  Char - |        ASCII  45
//  Char . |        ASCII  46
//  Char / |        ASCII  47
//  Char 0 |        ASCII  48
//  Char 1 |        ASCII  49
//  Char 2 |        ASCII  50
//  Char 3 |        ASCII  51
//  Char 4 |        ASCII  52
//  Char 5 |        ASCII  53
//  Char 6 |        ASCII  54
//  Char 7 |        ASCII  55
//  Char 8 |        ASCII  56
//  Char 9 |        ASCII  57
//  Char : |        ASCII  58
//  Char ; |        ASCII  59
//  Char < |        ASCII  60
//  Char = |        ASCII  61
//  Char > |        ASCII  62
//  Char ? |        ASCII  63
//  Char @ |        ASCII  64
//  Char A |        ASCII  65
//  Char B |        ASCII  66
//  Char C |        ASCII  67
//  Char D |        ASCII  68
//  Char E |        ASCII  69
//  Char F |        ASCII  70
//  Char G |        ASCII  71
//  Char H |        ASCII  72
//  Char I |        ASCII  73
//  Char J |        ASCII  74
//  Char K |        ASCII  75
//  Char L |        ASCII  76
//  Char M |        ASCII  77
//  Char N |        ASCII  78
//  Char O |        ASCII  79
//  Char P |        ASCII  80
//  Char Q |        ASCII  81
//  Char R |        ASCII  82
//  Char S |        ASCII  83
//  Char T |        ASCII  84
//  Char U |        ASCII  85
//  Char V |        ASCII  86
//  Char W |        ASCII  87
//  Char X |        ASCII  88
//  Char Y |        ASCII  89
//  Char Z |        ASCII  90
//  Char [ |        ASCII  91
//  Char \ |        ASCII  92
//  Char ] |        ASCII  93
//  Char ^ |        ASCII  94
//  Char _ |        ASCII  95
//  Char ` |        ASCII  96
//  Char a |        ASCII  97
//  Char b |        ASCII  98
//  Char c |        ASCII  99
//  Char d |        ASCII  100
//  Char e |        ASCII  101
//  Char f |        ASCII  102
//  Char g |        ASCII  103
//  Char h |        ASCII  104
//  Char i |        ASCII  105
//  Char j |        ASCII  106
//  Char k |        ASCII  107
//  Char l |        ASCII  108
//  Char m |        ASCII  109
//  Char n |        ASCII  110
//  Char o |        ASCII  111
//  Char p |        ASCII  112
//  Char q |        ASCII  113
//  Char r |        ASCII  114
//  Char s |        ASCII  115
//  Char t |        ASCII  116
//  Char u |        ASCII  117
//  Char v |        ASCII  118
//  Char w |        ASCII  119
//  Char x |        ASCII  120
//  Char y |        ASCII  121
//  Char z |        ASCII  122
//  Char { |        ASCII  123
//  Char | |        ASCII  124
//  Char } |        ASCII  125
//  Char ~ |        ASCII  126
//  Char ⌂ |        ASCII  127
//  Char  |        ASCII  128
//  Char  |        ASCII  129
//  Char é |        ASCII  130
//  Char â |        ASCII  131
//  Char 
//        |        ASCII  132
//  Char à |        ASCII  133
//  Char  |        ASCII  134
//  Char ç |        ASCII  135
//  Char ê |        ASCII  136
//  Char ë |        ASCII  137
//  Char è |        ASCII  138
//  Char ï |        ASCII  139
//  Char î |        ASCII  140
//  Char  |        ASCII  141
//  Char  |        ASCII  142
//  Char  |        ASCII  143
//  Char  |        ASCII  196
//  Char ┼ |        ASCII  197
//  Char ╞ |        ASCII  198
//  Char ╟ |        ASCII  199
//  Char ╚ |        ASCII  200
//  Char ╔ |        ASCII  201
//  Char ╩ |        ASCII  202
//  Char ╦ |        ASCII  203
//  Char ╠ |        ASCII  204
//  Char ═ |        ASCII  205
//  Char ╬ |        ASCII  206
//  Char ╧ |        ASCII  207
//  Char ╨ |        ASCII  208
//  Char ╤ |        ASCII  209
//  Char ╥ |        ASCII  210
//  Char ╙ |        ASCII  211
//  Char ╘ |        ASCII  212
//  Char ╒ |        ASCII  213
//  Char ╓ |        ASCII  214
//  Char ╫ |        ASCII  215
//  Char ╪ |        ASCII  216
//  Char ┘ |        ASCII  217
//  Char ┌ |        ASCII  218
//  Char █ |        ASCII  219
//  Char ▄ |        ASCII  220
//  Char ▌ |        ASCII  221
//  Char ▐ |        ASCII  222
//  Char ▀ |        ASCII  223
//  Char ض |        ASCII  224
//  Char ط |        ASCII  225
//  Char ظ |        ASCII  226
//  Char ع |        ASCII  227
//  Char غ |        ASCII  228
//  Char ف |        ASCII  229
//  Char µ |        ASCII  230
//  Char ق |        ASCII  231
//  Char ك |        ASCII  232
//  Char ل |        ASCII  233
//  Char م |        ASCII  234
//  Char ن |        ASCII  235
//  Char ه |        ASCII  236
//  Char و |        ASCII  237
//  Char ى |        ASCII  238
//  Char ي |        ASCII  239
//  Char ≡ |        ASCII  240