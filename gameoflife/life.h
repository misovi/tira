#include<vector>
//const int maxrow = 20, maxcol = 60;    //  grid dimensions
class Life {
private:
  int maxrow = 20;
  int maxcol = 60;
  std::vector<std::vector<int>> grid;
  //int grid[maxrow][maxcol];  //  allows for two extra rows and columns
  int neighbor_count(int row, int col);
public:
  void neighbour_count(int row, int col);
  void instructions();
  void initialize();
  void print();
  void update();
  bool user_says_yes();
  void setUp();
};
