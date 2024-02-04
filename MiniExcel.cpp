#include <iostream>
#include <cctype>
#include <string>
#include <Windows.h>
#include <conio.h>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib> // Including for system("cls") or system("clear")
#ifdef _WIN32
// Including for strlen on Unix-based systems
#endif

using namespace std;

template <typename T>

class MiniExcel
{
    class Cell
    {
    public:
        T data;
        Cell *up;
        Cell *down;
        Cell *left;
        Cell *right;
        Cell(T val)
        {
            data = val;
            up = nullptr;
            down = nullptr;
            left = nullptr;
            right = nullptr;
        }
    };

    //................. Iterator class

    class Iterator
    {
    public:
        Cell *iter;

        Iterator(Cell *currentCell)
        {
            iter = currentCell;
        }

        Iterator &operator++() // Pre incrementing to move right
        {
            iter = iter->right;
            return *this;
        }

        Iterator &operator--() // Pre decrementing to move left
        {
            iter = iter->left;
            return *this;
        }

        Iterator &operator++(int) // Post incrementing to move down
        {
            iter = iter->down;
            return *this;
        }

        Iterator &operator--(int) // Post decrementing to move up
        {
            iter = iter->up;
            return *this;
        }

        T &operator*() // Returns data of cell
        {
            return iter->data;
        }

        bool operator==(const Iterator &other) const
        {
            return iter == other.iter;
        }

        bool operator!=(const Iterator &other) const
        {
            return iter != other.iter;
        }
    };

    Iterator Start()
    {
        Cell *temp = current;
        while (temp->left)
        {
            temp = temp->left;
        }
        while (temp->up)
        {
            temp = temp->up;
        }

        return Iterator(temp);
    }

    Iterator End()
    {

        return Iterator(nullptr);
    }

public:
    Cell *current;
    vector<string> clipboardData; // For storing copied or cut data
    bool isColumn;
    Cell *firstCell;

    // Constructor of MiniExcel class
    MiniExcel()
    {
        current = new Cell("1"); // Initializing 1st element
        firstCell = current;
        current->left = nullptr;

        // Initializing 1st row
        for (int i = 0; i < 4; i++)
        {
            Cell *Row1 = new Cell("1");
            current->right = Row1;
            Row1->left = current;
            Row1->up = nullptr;
            current = Row1;
        }
        current = firstCell; // Resetting the current pointer to the first cell of the 1st row

        // Initializing 2nd row
        Cell *row2Start = new Cell("2");
        current->down = row2Start;
        row2Start->up = current;

        for (int i = 0; i < 4; i++)
        {
            Cell *Row2 = new Cell("2");
            row2Start->right = Row2;
            Row2->left = row2Start;
            Row2->up = current;
            row2Start = Row2;
        }
        current = firstCell;

        // Initializing 3rd row
        Cell *row3Start = new Cell("3");
        current->down->down = row3Start;
        row3Start->up = current->down;

        for (int i = 0; i < 4; i++)
        {
            Cell *Row3 = new Cell("3");
            row3Start->right = Row3;
            Row3->left = row3Start;
            Row3->up = current;
            row3Start = Row3;
        }
        current = firstCell;

        // Initializing 4th row
        Cell *row4Start = new Cell("4");
        current->down->down->down = row4Start;
        row4Start->up = current->down->down;

        for (int i = 0; i < 4; i++)
        {
            Cell *Row4 = new Cell("4");
            row4Start->right = Row4;
            Row4->left = row4Start;
            Row4->up = current;
            row4Start = Row4;
        }
        current = firstCell;

        // Initializing 5th row
        Cell *row5Start = new Cell("5");
        current->down->down->down->down = row5Start;
        row5Start->up = current->down->down->down;

        for (int i = 0; i < 4; i++)
        {
            Cell *Row5 = new Cell("5");
            row5Start->right = Row5;
            Row5->left = row5Start;
            Row5->up = current;
            row5Start = Row5;
            row5Start->down = nullptr;
        }

        current = firstCell; // Resetting the current pointer to the first cell of the 1st row

        Cell *currentPtr = current;       // Pointer to the current cell
        Cell *nextRowPtr = current->down; // Pointer to the cell in the next row

        for (int i = 1; i <= 16; i++) // Making up and down connections between 1 to 4 columns
        {
            currentPtr = currentPtr->right;
            nextRowPtr = nextRowPtr->right;

            currentPtr->down = nextRowPtr;
            nextRowPtr->up = currentPtr;

            if (i % 4 == 0)
            {
                while (currentPtr->left && nextRowPtr->left)
                {
                    currentPtr = currentPtr->left;
                    nextRowPtr = nextRowPtr->left;
                }
                currentPtr = currentPtr->down;
                nextRowPtr = nextRowPtr->down;
            }
        }

        current = firstCell;
        //   checking Inserting row above below by changing the current
        // current = current->right;
    }

    // function to insert row above the current cell
    void InsertRowAbove()
    {
        Cell *temp = current;
        Cell *row = new Cell("0");
        while (temp->left)
        {
            temp = temp->left;
        }

        if (temp->up == nullptr)
        {
            row->down = temp;
            temp->up = row;
            row->up = nullptr;
            while (temp->right)
            {
                Cell *rowElement = new Cell("0");
                row->right = rowElement;
                rowElement->left = row;
                temp = temp->right;
                temp->up = rowElement;
                rowElement->down = temp;
                row = row->right;
                rowElement->up = nullptr;
            }
        }
        else
        {
            row->down = temp;
            row->up = temp->up;
            temp->up->down = row;
            temp->up = row;

            while (temp->right)
            {
                Cell *rowElement = new Cell("0");
                rowElement->left = row;
                row->right = rowElement;
                temp = temp->right;
                rowElement->up = temp->up;
                temp->up->down = rowElement;
                rowElement->down = temp;
                temp->up = rowElement;
                row = row->right;
            }
        }
    }

    // function to insert row below the current cell
    void InsertRowBelow()
    {
        Cell *temp = current;
        Cell *row = new Cell("0");

        // Finding the last cell in the row below the current row
        while (temp->left)
        {
            temp = temp->left; // moving temporary to the left most
        }

        // If there is a row below the current row
        if (temp->down == nullptr)
        {
            // Inserting the new row below the last cell in the row below
            row->up = temp;
            temp->down = row;
            row->down = nullptr;

            // Connect the cells in the new row horizontally
            while (temp->right)
            {
                Cell *NewRow = new Cell("0");
                NewRow->left = row;
                row->right = NewRow;
                temp = temp->right;
                temp->down = NewRow;
                NewRow->up = temp;
                row = NewRow;
                NewRow->down = nullptr;
            }
        }
        else
        {
            row->up = temp;
            row->down = temp->down;
            temp->down->up = row;
            temp->down = row;
            while (temp->right)
            {
                Cell *NewRow = new Cell("0");
                NewRow->left = row;
                row->right = NewRow;
                temp = temp->right;
                NewRow->up = temp;
                NewRow->down = temp->down;
                temp->down->up = NewRow;
                temp->down = NewRow;
                row = row->right;
            }
        }
    }

    // function to insert column to the left of the current cell
    void insertColumnToLeft()
    {

        Cell *currentCell = current;

        // Creating the first cell of the new column
        Cell *newColumn = new Cell("0");

        // Moving to the leftmost cell in the row
        while (currentCell->up)
        {
            currentCell = currentCell->up;
        }

        // If there is no cell to the left of the current cell, insert the new column at the beginning of the row
        if (currentCell->left == nullptr)
        {
            // Connecting the new column to the right of the current cell
            newColumn->right = currentCell;

            // Connecting the current cell to the left of the new column
            currentCell->left = newColumn;

            // Setting the left side of the new column to null since it is at the beginning of the row
            newColumn->left = nullptr;

            // Inserting remaining cells in the new column
            while (currentCell->down)
            {
                // Create a new cell for the new column
                Cell *newColumnElement = new Cell("0");

                // Connect the new cell to the bottom of the previous cell in the new column
                newColumn->down = newColumnElement;

                // Connect the previous cell in the new column to the top of the new cell
                newColumnElement->up = newColumn;

                // Move to the next cell in the row
                currentCell = currentCell->down;

                // Connect the new cell to the right of the next cell in the row
                newColumnElement->right = currentCell;

                // Connect the next cell in the row to the left of the new cell
                currentCell->left = newColumnElement;

                // Set the left side of the new cell to null since it is at the end of the column
                newColumnElement->left = nullptr;

                // Move the temporary column element to the next cell in the new column
                newColumn = newColumn->down;
            }
        }
        else
        {
            // Insert the new column to the right of the cell to the left of the current cell
            newColumn->right = currentCell;

            // Connect the cell to the left of the current cell to the left of the new column
            newColumn->left = currentCell->left;

            // Connect the cell to the left of the current cell to the right of the new column
            currentCell->left->right = newColumn;

            // Connect the current cell to the left of the new column
            currentCell->left = newColumn;

            // Insert remaining cells in the new column
            while (currentCell->down)
            {
                // Create a new cell for the new column
                Cell *newColumnElement = new Cell("0");

                // Connect the new cell to the bottom of the previous cell in the new column
                newColumn->down = newColumnElement;

                // Connect the previous cell in the new column to the top of the new cell
                newColumnElement->up = newColumn;

                // Move to the next cell in the row
                currentCell = currentCell->down;

                // Connect the new cell to the right of the next cell in the row
                newColumnElement->right = currentCell;

                // Connect the new cell to the left of the next cell in the row
                newColumnElement->left = currentCell->left;

                // Connect the cell to the left of the next cell in the row to the right of the new cell
                currentCell->left->right = newColumnElement;

                // Connect the next cell in the row to the left of the new cell
                currentCell->left = newColumnElement;

                // Move the temporary column element to the next cell in the new column
                newColumn = newColumn->down;
            }
        }
    }

    // function to insert column to the right of the current cell
    void InsertColumnToRight()
    {
        // Getting the current cell
        Cell *temp = current;
        // Create the new column
        Cell *col = new Cell("0");

        // Moving to the top of the current cell's column
        while (temp->up)
        {
            temp = temp->up;
        }

        // If there is no cell to the right of the current cell, insert the new column at the end of the row
        if (temp->right == nullptr)
        {
            col->left = temp;
            temp->right = col;
            col->right = nullptr;

            // Loop till the row end
            while (temp->down)
            {
                Cell *NewColElement = new Cell("0");
                col->down = NewColElement;
                NewColElement->up = col;
                temp = temp->down;
                NewColElement->left = temp;
                temp->right = NewColElement;
                NewColElement->right = nullptr;
                col = col->down;
            }
        }
        else
        {
            // Inserting the new column between the current cell and the cell to its right
            col->left = temp;
            col->right = temp->right;
            temp->right->left = col;
            temp->right = col;

            // Loop till the col end
            while (temp->down)
            {
                Cell *colElement = new Cell("0");
                col->down = colElement;
                colElement->up = col;
                temp = temp->down;
                colElement->left = temp;
                colElement->right = temp->right;
                temp->right->left = colElement;
                temp->right = colElement;
                col = col->down;
            }
        }
    }

    // function to clear the row data
    void clearRow()
    {
        Cell *temp = current;
        while (temp->right)
        {

            temp = temp->right;
        }
        while (temp)
        {
            temp->data = "_";
            temp = temp->left;
        }
    }
    // function to clear the column data
    void clearColumn()
    {
        Cell *temp = current;
        // cout << temp->down->data << endl;
        // cout << temp->down->down->data << endl;
        while (temp->up)
        {
            temp = temp->up;
        }
        while (temp)
        {
            temp->data = "_";
            temp = temp->down;
        }
    }

    // Function to set text color
    void setColor(int textColor, int bgColor)
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, textColor | (bgColor << 4));
    }

    // Function to reset text color to default
    void resetColor()
    {
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(hConsole, 15); // Assuming default color is white text on black background
    }
    void setConsoleColor(int color)
    {
#ifdef _WIN32
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
#else
        cout << "\033[1;" << color << "m"; // ANSI escape code for setting text color
#endif
    }

    void resetConsoleColor()
    {
#ifdef _WIN32
        setConsoleColor(7); // Reset to default color on Windows
#else
        cout << "\033[0m"; // ANSI escape code for resetting text color on Unix-based systems
#endif
    }

    // Including the necessary header for setw
    // funtion to Print Sheet
    void PrintSheet()
    {
        // Setting color for the border
        setConsoleColor(11); // Bright cyan
        cout << "+";
        for (int i = 0; i < 6 * 7; i++)
        {
            cout << "-";
        }
        cout << "+" << endl;
        resetConsoleColor();

        // Finding the top-left cell of the sheet
        Cell *topLeft = current;
        // cout << "-";
        while (topLeft->up)
        {
            topLeft = topLeft->up;
        }

        while (topLeft->left)
        {
            topLeft = topLeft->left;
        }

        // Start printing the sheet from the top-left cell
        Cell *rowStart = topLeft;

        while (rowStart)
        {
            // Printing line above each row
            setConsoleColor(11); // Bright cyan
            cout << "|";
            resetConsoleColor();

            Cell *colStart = rowStart;

            while (colStart)
            {
                if (colStart == current)
                {
                    setColor(31, 51); // Highlight color
                    cout << " " << setw(5) << colStart->data << " ";
                    resetColor();

                    setConsoleColor(11); // Bright cyan
                    cout << "|";
                    resetConsoleColor();
                }
                else
                {
                    // Setting color for cell data
                    setConsoleColor(14);                             // Yellow
                    cout << "|" << setw(5) << colStart->data << " "; // Increasing cell size
                    // Setting color for the border
                    setConsoleColor(11); // Bright cyan
                    cout << "|";
                    resetConsoleColor();
                }

                colStart = colStart->right;
            }

            cout << endl;

            // Setting color for the border
            setConsoleColor(11); // Bright cyan
            cout << "+";
            for (int i = 0; i < 6 * 7; ++i)
            {
                cout << "-";
            }
            cout << "+" << endl;
            resetConsoleColor();

            rowStart = rowStart->down;
        }
    }

    // function to delete a complete row
    void DeleteRow()
    {
        Cell *topmostCellInRow = current;
        Cell *tempCell;

        // Moving to the topmost cell in the current row
        while (topmostCellInRow->left)
        {
            topmostCellInRow = topmostCellInRow->left;
        }

        tempCell = topmostCellInRow;

        // If it is the only row, nothing to delete
        if (topmostCellInRow->up == nullptr && topmostCellInRow->down == nullptr)
        {
            return;
        }

        // If it's the topmost row
        else if (topmostCellInRow->up == nullptr)
        {
            current = current->down; // Moving current down
            while (topmostCellInRow)
            {
                topmostCellInRow->down->up = nullptr;       // Updating up connection of the down pointer
                topmostCellInRow = topmostCellInRow->right; // Moving across the row
                tempCell = topmostCellInRow;
            }
        }

        // If it's the bottommost row
        else if (current->down == nullptr)
        {
            current = current->up; // Moving current up
            while (topmostCellInRow)
            {
                topmostCellInRow->up->down = nullptr;       // Updating down connection of the up pointer
                topmostCellInRow = topmostCellInRow->right; // Moving across the row
                tempCell = topmostCellInRow;
            }
        }

        // For other rows
        else
        {
            current = current->up; // Moving current up
            while (topmostCellInRow)
            {
                tempCell->up->down = tempCell->down;        // Updating down connection of the up pointer
                tempCell->down->up = tempCell->up;          // Updating up connection of the down pointer
                topmostCellInRow = topmostCellInRow->right; // Moving across the row
                tempCell = topmostCellInRow;
            }
        }
    }

    // function to delete a complete column
    void DeleteColumn()
    {
        Cell *topmostCellInColumn = current; // Pointing to the topmost cell in the current column
        Cell *tempCell = nullptr;            // Temporary pointer for traversal and link adjustments

        // Moving to the topmost cell in the current column
        while (topmostCellInColumn->up)
        {
            topmostCellInColumn = topmostCellInColumn->up;
        }

        tempCell = topmostCellInColumn;

        // If it is the only column, nothing to delete
        if (topmostCellInColumn->left == nullptr && topmostCellInColumn->right == nullptr)
        {
            return;
        }

        // If it's the leftmost column
        else if (topmostCellInColumn->left == nullptr)
        {
            current = current->right; // Moving current to the right
            while (topmostCellInColumn)
            {
                tempCell->right->left = nullptr;                 // Updating left connection of the right pointer
                topmostCellInColumn = topmostCellInColumn->down; // Moving down the column
                tempCell = topmostCellInColumn;
            }
        }

        // If it's the rightmost column
        else if (current->right == nullptr)
        {
            current = current->left; // Moving current to the left
            while (topmostCellInColumn)
            {
                tempCell->left->right = nullptr;                 // Updating left connection of the right pointer
                topmostCellInColumn = topmostCellInColumn->down; // Moving down the column
                tempCell = topmostCellInColumn;
            }
        }

        // For other columns
        else
        {
            current = current->left; // Moving current to the left
            while (topmostCellInColumn)
            {
                tempCell->left->right = tempCell->right;         // Updating left connection of the right pointer
                tempCell->right->left = tempCell->left;          // Updating right connection of the left pointer
                topmostCellInColumn = topmostCellInColumn->down; // Moving down the column
                tempCell = topmostCellInColumn;
            }
        }
    }

    // function to insert cell by using left shift
    void DeleteCellByLeftShift()
    {
        Cell *temp = this->current;

        // Checking if the current cell is not the last cell in the row
        if (temp->right != nullptr)
        {
            Cell *tempNext = temp->right;

            // Shifting the data to the left
            while (tempNext != nullptr)
            {
                temp->data = tempNext->data;
                temp = temp->right;
                tempNext = tempNext->right;
            }

            // Setting the data of the last cell to indicate it's unused
            temp->data = "..."; // Replacing with the desired placeholder value
        }
    }

    // function to insert cell by using right shift
    void InsertCellByRightShift()
    {
        Cell *temp = current;
        while (current->right)
        {
            current = current->right;
        }
        InsertColumnToRight();
        while (current != temp)
        {
            current->right->data = current->data;
            current = current->left;
        }

        current->data = "...";
    }

    // Function to delete the current cell and shift cells below it up
    void DeleteCellByUpShift()
    {
        // Step 1: Initialization
        Cell *temp = this->current; // Starting from the current cell

        // Checking if the current cell has a cell below it
        if (temp->down != nullptr)
        {
            // Step 2: Shifting the data upward
            Cell *tempNext = temp->down; // Initializing tempNext to the cell below temp
            while (tempNext != nullptr)  // Continuing until there are no more cells below
            {
                temp->data = tempNext->data; // Shifting data from tempNext to temp
                temp = temp->down;           // Moving temp downward
                tempNext = tempNext->down;   // Moving tempNext downward
            }

            temp->data = "...";
        }
    }

    // function to insert cell by using down shift
    void InsertCellByDownShift()
    {
        Cell *temp = current;
        while (current->down)
        {
            current = current->down;
        }
        InsertRowBelow();
        while (current != temp)
        {
            current->down->data = current->data;
            current = current->up;
        }

        current->data = "...";
    }

    // function to Check if digit or Not
    bool IsConvertibleToInt(string &str)
    {
        // Checking if the string is convertible to an integer
        for (char c : str)
        {
            if (!isdigit(c))
            {
                return false;
            }
        }
        return true;
    }

    // Function to Get Sum in a certain range
    void GetRangeSum(Cell *start, Cell *end, Cell *location)
    {
        int sum = 0;

        bool flag = checkTraversingLocation(start, end);

        if (flag)
        {
            while (start != end->right)
            {
                start = start->right;
                sum += stoi(start->data);
            }
        }
        else
        {
            while (start != end->down)
            {

                sum += stoi(start->data);
                start = start->down;
            }
        }
        current = location;
        location->data = to_string(sum);
    }
    // Function to Get Average in a certain range
    void GetRangeAverage(Cell *start, Cell *end, Cell *location)
    {
        double sum = 0;
        int count = 0;

        bool flag = checkTraversingLocation(start, end);

        if (flag)
        {
            while (start != end->right)
            {
                sum += stoi(start->data);
                count++;
                start = start->right;
            }
        }

        else
        {
            while (start != end->down)
            {
                sum += stoi(start->data);
                count++;
                start = start->down;
            }
        }

        sum = sum / count;
        current = location;
        location->data = to_string(sum);
    }

    void MoveCurrentToLeft()
    {
        if (current->left)
        {
            current = current->left; // Moving left
        }
    }

    void MoveCurrentRight()
    {
        if (current->right)
        {
            current = current->right; // Moving right
        }
    }

    void MoveCurrentToUp()
    {
        if (current->up)
        {
            current = current->up; // Moving up
        }
    }

    void MoveCurrentToDown()
    {
        if (current->down)
        {
            current = current->down; // Moving down
        }
    }

    // Function for checking traversing
    bool checkTraversingLocation(Cell *start, Cell *end)
    {
        while (start != nullptr)
        {
            if (start == end)
            {
                return true;
            }
            start = start->down;
        }
        return false;
    }

    // Function to cut the data in a specified range
    void Cut(Cell *startCell, Cell *endCell)
    {
        clipboardData.clear();
        bool moveRight = checkTraversingLocation(startCell, endCell);
        isColumn = moveRight;

        if (moveRight)
        {
            while (startCell != endCell->right)
            {
                clipboardData.push_back(startCell->data);
                startCell->data = "-";
                startCell = startCell->right;
            }
        }

        else
        {
            while (startCell != endCell->down)
            {
                clipboardData.push_back(startCell->data);
                startCell->data = "-";
                startCell = startCell->down;
            }
        }
    }

    // Function to copy the data in a specified range
    void Copy(Cell *startCell, Cell *endCell)
    {
        clipboardData.clear();
        bool moveRight = checkTraversingLocation(startCell, endCell);
        isColumn = moveRight;

        if (moveRight)
        {
            while (startCell != endCell->right)
            {
                clipboardData.push_back(startCell->data);
                startCell = startCell->right;
            }
        }
        else
        {
            while (startCell != endCell->down)
            {
                clipboardData.push_back(startCell->data);
                startCell = startCell->down;
            }
        }
    }

    // Function for pasting the copied or cut data
    void Paste()
    {

        if (isColumn) // Finding if column or not , if it is true then row was copied
        {
            for (int i = 0; i < clipboardData.size(); i++)
            {
                current->data = clipboardData[i]; // copying data

                if (current->right == nullptr && i != clipboardData.size() - 1) // Checking if the columns are ended and still their are elements in vector
                {
                    Cell *newCell = new Cell("0"); // NewCell
                    newCell->left = current;       // Left Connection
                    current->right = newCell;      // right Connection
                }
                else if (current->right == nullptr && i == clipboardData.size() - 1) // If the last column and also the last row so do not create an extra cell
                {
                    current = current;
                }
                else
                {
                    current = current->right;
                }
            }
        }

        else // Checking if column was copied
        {
            for (int i = 0; i < clipboardData.size(); i++)
            {
                current->data = clipboardData[i];
                if (current->down == nullptr) // Checking if the columns are ended and still their are elements in vector
                {
                    Cell *newCell = new Cell("0");
                    newCell->up = current;
                    current->down = newCell;
                }
                else if (current->down == nullptr && i == clipboardData.size() - 1) // If the last column and also the last row so do not create an extra cell
                {
                    current = current;
                }
                else
                {
                    current = current->down;
                }
            }
        }
    }

    int TakeInputForCell(string input)
    {
        int cell;
        cout << input;
        while (_kbhit())
        {
            _getch();
        }
        cin >> cell;
        return cell - 1; // Adjusting for 0-based indexing (if your Excel sheet is 0-indexed)
    }

    void ChageCellData()
    {
        cout << "Enter data of current: ";

        while (_kbhit()) // Clearing any echo
        {
            _getch();
        }
        cin >> current->data;
    }

    /*void gotoxy(int x, int y)
    {
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }*/

    // Function to display title
    void printWelcomeBanner()
    {
        cout << "***************************************************************" << endl;
        cout << "*                                                             *  " << endl;
        cout << "*                  MINI EXCEL PROJECT                         *" << endl;
        cout << "*                                                             *" << endl;
        cout << "***************************************************************" << endl;
        cout<<endl;
        cout<<"Press any key to continue :"<<endl;
    }
    void DisplayMenu()
    {
        system("cls");
        cout << "Excel Simulator Menu:" << endl;
        cout << "---------------------" << endl;
        cout << "Arrow Up        - Move Current Up" << endl;
        cout << "Arrow Down      - Move Current Down" << endl;
        cout << "Arrow Left      - Move Current Left" << endl;
        cout << "Arrow Right     - Move Current Right" << endl;
        cout << "Ctrl + Up       - Insert Row Above" << endl;
        cout << "Ctrl + Down     - Insert Row Below" << endl;
        cout << "Ctrl + Right    - Insert Column To Right" << endl;
        cout << "Ctrl + L        - Insert Column To Left" << endl;
        cout << "Shift + R       - Insert Cell By Right Shift" << endl;
        cout << "Shift + D       - Insert Cell By Down Shift" << endl;
        cout << "Delete + L      - Delete Cell By Left Shift" << endl;
        cout << "Delete + U      - Delete Cell By Up Shift" << endl;
        cout << "Delete + C      - Delete Column" << endl;
        cout << "Delete + R      - Delete Row" << endl;
        cout << "Tab + C         - Clear Column" << endl;
        cout << "Tab + R         - Clear Row" << endl;
        cout << "Shift + S       - Get Range Sum" << endl;
        cout << "Shift + A       - Get Range Average" << endl;
        cout << "Ctrl + W        - Copy Range" << endl;
        cout << "Ctrl + X        - Cut Range" << endl;
        cout << "Ctrl + V        - Paste Range" << endl;
        cout << "Ctrl + S        - Save Sheet" << endl;
        cout << "Insert          - Change Cell Data" << endl;
        cout << "M               - Display Menu" << endl;
        cout << "Esc             - Exit" << endl;
    }

    Cell *GetCell(int row, int col)
    {
        Cell *temp = current;

        // Traversing to the specified row
        for (int i = 0; i < row && temp->down; i++)
        {

            temp = temp->down;
        }

        // Traversing to the specified column
        for (int i = 0; i < col && temp->right; i++)
        {
            temp = temp->right;
        }

        return temp; // Returning a pointer to the desired cell
    }

    // file handling

    // Function to load the sheet from a file
    void LoadSheet()
    {
        ifstream file("sheet.txt", ios::in);
        if (!file.is_open())
        {
            cerr << "Error opening file for reading" << endl;
            return;
        }

        Cell *tempCell = nullptr;
        Cell *tempRow = nullptr;

        string line;
        while (getline(file, line))
        {
            vector<string> cellValues;
            splitString(line, cellValues, ',');

            while (!cellValues.empty())
            {
                Cell *cellElement = new Cell(cellValues.front()); // Creating the first element of the row
                cellValues.erase(cellValues.begin());             // Erasing the first value

                if (tempCell == nullptr && tempRow == nullptr)
                {
                    tempCell = cellElement;
                    tempRow = tempCell;
                    current = tempCell;
                    firstCell = tempCell;
                }
                else if (tempCell == nullptr && tempRow != nullptr)
                {
                    tempCell = cellElement;
                    tempRow->down = cellElement;
                    cellElement->up = tempRow;
                    tempRow = tempRow->down;
                }
                else
                {
                    tempCell->right = cellElement;
                    cellElement->left = tempCell;
                    tempCell = tempCell->right;
                }
            }
            tempCell = nullptr;
        }

        // Connecting rows and columns
        Cell *conec1 = firstCell;
        Cell *conec2 = firstCell->down;

        Cell *tempConec1 = conec1;
        Cell *tempConec2 = conec2;

        while (conec2 != nullptr)
        {
            tempConec1 = conec1;
            tempConec2 = conec2;
            while (tempConec2 != nullptr)
            {
                tempConec1->down = tempConec2;
                tempConec2->up = tempConec1;
                tempConec1 = tempConec1->right;
                tempConec2 = tempConec2->right;
            }
            conec1 = conec2;
            conec2 = conec2->down;
        }

        file.close();
    }

    // Function to save sheet to a file
    void SaveSheet()
    {
        fstream file;
        file.open("sheet.txt", ios::out);

        for (Iterator it = Start(); it != End(); it++)
        {
            bool firstElement = true; // Flag to avoid a comma at very end of row

            for (Iterator t = it; t != End(); ++t)
            {
                if (!firstElement)
                {
                    file << ",";
                }
                else
                {
                    firstElement = false;
                }

                file << *t;
            }
            file << endl;
        }

        file.close();
    }

    // Function to split a string into a vector based on a delimiter
    void splitString(const string &inputString, vector<string> &outputVector, char delimiter)
    {
        string token;
        for (char c : inputString)
        {
            if (c == delimiter)
            {
                outputVector.push_back(token);
                token.clear();
            }
            else
            {
                token += c;
            }
        }
        if (!token.empty())
        {
            outputVector.push_back(token);
        }
    }

    // Function to parse a specific element from a comma-separated string
    T parsing(const string &line, int num)
    {
        int count = 1;
        string temp;
        for (char c : line)
        {
            if (c == ',')
            {
                count++;
            }
            else if (count == num)
            {
                temp += c;
            }
        }
        try
        {
            return stoi(temp);
        }
        catch (const invalid_argument &e)
        {
            cerr << "Invalid argument: " << e.what() << endl;
            // Handling the error, possibly by returning a special value or throwing a different exception.
            return T(); // Returning a default value for T
        }
    }
};

int main()
{
    MiniExcel<string> excel;
    excel.LoadSheet();
    excel.printWelcomeBanner();
    getch();
    system("cls");
    Sleep(500);
    excel.printWelcomeBanner();
    excel.DisplayMenu();
    Sleep(500);
    getch();
    bool running = true;

    while (running)
    {
        // Moving current cell in the Excel sheet using arrow keys
        if (GetAsyncKeyState(VK_UP) && 1)
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.MoveCurrentToUp();
            excel.PrintSheet();
        }

        if (GetAsyncKeyState(VK_DOWN))
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.MoveCurrentToDown();
            excel.PrintSheet();
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.MoveCurrentToLeft();
            excel.PrintSheet();
        }

        if (GetAsyncKeyState(VK_RIGHT))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.MoveCurrentRight();
            excel.PrintSheet();
        }

        // Handling key combinations for different functions using Ctrl key

        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_UP)) // function1
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.InsertRowAbove();
            excel.PrintSheet();
        }
        // Function2
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_DOWN))
        {
            // Shift + Up Arrow: Insert row below
            system("cls");
            excel.printWelcomeBanner();
            excel.InsertRowBelow();
            excel.PrintSheet();
        }
        // function3
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState(VK_RIGHT))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.InsertColumnToRight();
            excel.PrintSheet();
        }
        // function4
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState('L'))
        {

            system("cls");
            excel.insertColumnToLeft();
            excel.printWelcomeBanner();
            excel.PrintSheet();
        }
        // function5
        if (GetAsyncKeyState(VK_SHIFT) & GetAsyncKeyState('R'))
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.InsertCellByRightShift();
            excel.PrintSheet();
        }
        // function6
        if (GetAsyncKeyState(VK_SHIFT) & GetAsyncKeyState('D'))
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.InsertCellByDownShift();
            excel.PrintSheet();
        }
        // function7
        if (GetAsyncKeyState(VK_DELETE) & GetAsyncKeyState('L'))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.DeleteCellByLeftShift();
            excel.PrintSheet();
        }
        // function8
        if (GetAsyncKeyState(VK_DELETE) & GetAsyncKeyState('U'))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.DeleteCellByUpShift();
            excel.PrintSheet();
        }
        // function9
        if (GetAsyncKeyState(VK_DELETE) & GetAsyncKeyState('C'))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.DeleteColumn();
            excel.PrintSheet();
        }
        // function10
        if (GetAsyncKeyState(VK_DELETE) & GetAsyncKeyState('R'))
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.DeleteRow();
            excel.PrintSheet();
        }
        // function11
        if (GetAsyncKeyState(VK_TAB) & GetAsyncKeyState('C'))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.clearColumn();
            excel.PrintSheet();
        }
        // function12
        if (GetAsyncKeyState(VK_TAB) & GetAsyncKeyState('R'))
        {

            system("cls");
            excel.printWelcomeBanner();
            excel.clearRow();
            excel.PrintSheet();
        }

        // function13
        if (GetAsyncKeyState(VK_SHIFT) & GetAsyncKeyState('S'))
        {
            // Input for the starting cell row and column
            int startRow = excel.TakeInputForCell("Enter starting cell row: ");
            int startCol = excel.TakeInputForCell("Enter starting cell column: ");

            // Input for the ending cell row and column
            int endRow = excel.TakeInputForCell("Enter ending cell row: ");
            int endCol = excel.TakeInputForCell("Enter ending cell column: ");

            // Input for the destination cell row and column
            int destinationRow = excel.TakeInputForCell("Enter destination cell row: ");
            int destinationCol = excel.TakeInputForCell("Enter destination cell column: ");

            // Calling the GetRangeSum function with the specified cells
            excel.GetRangeSum(excel.GetCell(startRow, startCol), excel.GetCell(endRow, endCol), excel.GetCell(destinationRow, destinationCol));

            // Clearing the console
            system("cls");

            // Printing the updated sheet
            excel.PrintSheet();
        }

        // function14
        if (GetAsyncKeyState(VK_SHIFT) & GetAsyncKeyState('A'))
        { // Input for the starting cell row and column
            int startRow = excel.TakeInputForCell("Enter starting cell row: ");
            int startCol = excel.TakeInputForCell("Enter starting cell column: ");

            // Input for the ending cell row and column
            int endRow = excel.TakeInputForCell("Enter ending cell row: ");
            int endCol = excel.TakeInputForCell("Enter ending cell column: ");

            // Input for the destination cell row and column
            int destinationRow = excel.TakeInputForCell("Enter destination cell row: ");
            int destinationCol = excel.TakeInputForCell("Enter destination cell column: ");

            // Calling the GetRangeSum function with the specified cells
            excel.GetRangeAverage(excel.GetCell(startRow, startCol), excel.GetCell(endRow, endCol), excel.GetCell(destinationRow, destinationCol));

            // Clearing the console
            system("cls");

            // Printing the updated sheet
            excel.PrintSheet();
        }
        // funtion15
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState('W'))
        {
            // copy funtion
            // Input for the starting cell row and column
            int startRow = excel.TakeInputForCell("Enter starting cell row: ");
            int startCol = excel.TakeInputForCell("Enter starting cell column: ");

            // Input for the ending cell row and column
            int endRow = excel.TakeInputForCell("Enter ending cell row: ");
            int endCol = excel.TakeInputForCell("Enter ending cell column: ");

            // Calling the GetRangeSum function with the specified cells
            excel.Copy(excel.GetCell(startRow, startCol), excel.GetCell(endRow, endCol));
            // Clearing the console
            system("cls");

            // Printing the updated sheet
            excel.PrintSheet();
        }
        // function16
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState('X'))
        {

            // cut funtion

            // Input for the starting cell row and column
            int startRow = excel.TakeInputForCell("Enter starting cell row: ");
            int startCol = excel.TakeInputForCell("Enter starting cell column: ");

            // Input for the ending cell row and column
            int endRow = excel.TakeInputForCell("Enter ending cell row: ");
            int endCol = excel.TakeInputForCell("Enter ending cell column: ");

            // Calling the GetRangeSum function with the specified cells
            excel.Cut(excel.GetCell(startRow, startCol), excel.GetCell(endRow, endCol));
            // Clear the console
            system("cls");

            // Printing the updated sheet
            excel.PrintSheet();
        }
        // function17
        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState('V'))
        {

            // paste funtion
            excel.Paste();
            system("cls");
            excel.PrintSheet();
        }

        if (GetAsyncKeyState(VK_CONTROL) & GetAsyncKeyState('S'))
        {

            excel.SaveSheet();
        }

        if (GetAsyncKeyState(VK_INSERT))
        {
            system("cls");
            excel.printWelcomeBanner();
            excel.ChageCellData();
            excel.PrintSheet();
        }

        if (GetAsyncKeyState(VK_ESCAPE))
        {
            break;
        }

        if (GetAsyncKeyState('M'))
        {
            system("cls");
            excel.DisplayMenu();
        }

        Sleep(200);
    }

    return 0;
}
