#define UNICODE 
enum COLORS{BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define COL 80
#define bg(c) (c+10)
#define BAR "\u2590"
// fucntion declarations
void clearScreen(void);
void setColors(short, short);
void resetColors(void);
void barChart(int []);
