#include <iostream>
#include <fstream>
#include <ncurses.h>
#include "colorPair.h"

#include <cctype>
#include <cstring>
#include <string> // for getline
// include files
#include "Queue.h"
using namespace std;
class Node
{
public:
	string word;
	Node *left;
	Node *right;
	int height;
	Node(string str)
	{
		word = str;
		height = 0;
		left = NULL;
		right = NULL;
	}
};
class AVLTree
{

public:
	Node *root;
	int temp;
	AVLTree()
	{
		root = NULL;
		temp = 0;
		makeTree();
	}
	// this read the file make tree
	void makeTree()
	{
		ifstream file;
		file.open("dictionary.txt");
		string str = "";
		while (getline(file, str))
		{
			str = strip(str);
			str = toLower(str);

			root = insert(root, str);
		}
		file.close();
	}
	string strip(string str)
	{
		int i = 0;
		string str1 = "";
		while (str[i] != '\0')
		{
			if ((str[i] >= 'a' && str[i] <= 'z') || ((str[i] >= 'A' && str[i] <= 'Z')))
			{
				str1 += str[i];
			}
			i++;
		}
		return str1;
	}
	string toLower(string &str)
	{
		string result = str;
		for (char &ch : result)
		{
			ch = tolower(ch);
		}
		return result;
	}
	int height(Node *n)
	{
		if (n)
			return n->height;
		else
			return -1;
	}
	int balance(Node *n)
	{
		return height(n->left) - height(n->right);
	}
	Node *leftRotation(Node *k1)
	{
		Node *k2 = k1->right;
		k1->right = k2->left;
		k2->left = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		return k2;
	}
	Node *rightRotation(Node *k1)
	{
		Node *k2 = k1->left;
		k1->left = k2->right;
		k2->right = k1;
		k1->height = max(height(k1->left), height(k1->right)) + 1;
		k2->height = max(height(k2->left), height(k2->right)) + 1;
		return k2;
	}
	Node *leftRightRotation(Node *k1)
	{
		k1->left = leftRotation(k1->left);
		return rightRotation(k1);
	}
	Node *rightLeftRotation(Node *k1)
	{
		k1->right = rightRotation(k1->right);
		return leftRotation(k1);
	}
	Node *insert(Node *root, string word)
	{
		if (!root)
		{
			root = new Node(word);
		}
		else if (word < root->word)
		{
			root->left = insert(root->left, word);
			if (balance(root) == 2)
			{
				if (balance(root->left) >= 0)
				{
					root = rightRotation(root);
				}
				else if (balance(root->left) < 0)
				{
					root = leftRightRotation(root);
				}
			}
		}
		else if (word > root->word)
		{
			root->right = insert(root->right, word);
			if (balance(root) == -2)
			{
				if (balance(root->right) <= 0)
				{
					root = leftRotation(root);
				}
				else if (balance(root->right) > 0)
				{
					root = rightLeftRotation(root);
				}
			}
		}
		root->height = max(height(root->left), height(root->right)) + 1;
		return root;
	}
	bool found(string str)
	{
		Node *temp = root;

		string str2 = root->word;

		while (temp)
		{

			if (temp->word == str)
			{
				return 1;
			}
			else if (str < temp->word)
				temp = temp->left;
			else
				temp = temp->right;
		}
		return 0;
	}
	void DisplayInorder(Node *n)
	{
		if (n)
		{

			DisplayInorder(n->left);
			// cout << n->word << "     Bal " << balance(n)<< endl;;

			printw(" :%s", (n->word).c_str());
			// printw(" bal %d",balance(n));
			// printw("\n");
			DisplayInorder(n->right);
		}
	}
	~AVLTree()
	{
		deleteTree(root);
	}
	void deleteTree(Node *n)
	{
		if (n)
		{
			deleteTree(n->left);
			deleteTree(n->right);
			delete n;
		}
	}
};
class NotePad
{
public:
	AVLTree *dictionary;
	ColorPair *color;
	Queue q;

	NotePad()
	{

		// Initialize ncurses
		initscr();	   // Start ncurses mode
		start_color(); // Enable color functionality
		attron(color->getColorPair(5));
		int rows, cols;
		getmaxyx(stdscr, rows, cols); // Get screen size
		mvhline(0, 0, '-', cols);	  // Top  and bottom border
		mvhline(rows - 1, 0, '-', cols);
		mvvline(0, 0, '|', rows); // Left and right border
		mvvline(0, cols - 1, '|', rows);
		keypad(stdscr, TRUE); // Enable keypad input (if needed for special keys)
		move(3, 7);
		dictionary = new AVLTree();
		color = new ColorPair();
		mainFunction();
	}

	void saveText()
	{
		ofstream file;
		file.open("save.txt");
		string str = "";
		while (!q.isempty())
		{
			str += q.dequeue();
		}
		file << str;
		file.close();
	}
	void loadfile()
	{
		q.makeQueueEmpty();
		ifstream file;
		file.open("save.txt");
		if (!file)
		{
			printw("\n\nFile not opened :  \n\n\n");
			return;
		}
		char ch;
		while (file.get(ch))
			q.enqueue(ch);

		file.close();
	}
	string getWord()
	{

		if (q.isempty())
			return "";
		listNode *lastSpace = q.rear;
		string str = "";
		while (lastSpace && lastSpace->ch != ' ' && lastSpace->ch != '\n')
		{
			char ch = lastSpace->ch;
			str = (ch) + str; // aa this one is not working
			// str.insert(0,1,ch);

			lastSpace = lastSpace->prevoius;
		}
		return str;
	}
	string toLower(const string &str)
	{
		string result = str; // Create a copy of the input string
		for (char &ch : result)
		{					  // Iterate through each character
			ch = tolower(ch); // Convert to lowercase
		}
		return result;
	}
	string removeLetter(string str, int i)
	{
		string temp = "";
		int j = 0;
		while (str[j] != '\0')
		{

			if (j == i)
			{
				j++;
				continue;
			}

			temp += str[j];
			j++;
		}
		return temp;
	}
	string omission(string str)
	{

		int i = 0;
		while (str[i] != '\0')
		{
			string temp = removeLetter(str, i);

			if (dictionary->found(temp))
			{
				return temp;
			}
			i++;
		}
		return "--";
	}
	string insertAt(string str, int pos, char c)
	{
		int i = 0;
		string temp = "";
		while (str[i] != '\0')
		{
			if (i == pos)
			{
				temp += c;
			}
			temp += str[i];
			i++;
		}
		return temp;
	}
	string insertion(string str)
	{

		int i = 0;
		string temp = "";
		while (str[i] != '\0')
		{
			char c = 'a';
			c--;
			while (c != 'z')
			{
				c++;
				temp = insertAt(str, i, c);

				if (dictionary->found(temp))
				{
					return temp;
				}
			}

			i++;
		}
		// for last index
		char c = 'a';
		c--;
		while (c != 'z')
		{
			c++;
			temp = str + c;
			if (dictionary->found(temp))
			{
				return temp;
			}
		}

		return "--";
	}
	string pairReverse(string str, int i)
	{
		int j = 0;
		string temp = "";
		while (str[j] != '\0')
		{
			if (i == j)
			{
				temp += str[j + 1];
				temp += str[j];
				j++;
				j++;
				continue;
			}
			temp += str[j];
			j++;
		}
		return temp;
	}
	string reverse(string str)
	{
		int length = str.length();
		for (int i = 0; i < length - 1; i++)
		{
			string temp = pairReverse(str, i);
			if (dictionary->found(temp))
			{
				return temp;
			}
		}
		return "--";
	}
	void spaceOperations(int x, int y)
	{
		string word = getWord();
		word = toLower(word);

		dictionary->temp = 0;
		// dictionary->DisplayInorder(dictionary->root);

		attron(color->getColorPair(6));
		move(y + 4, (x + q.length + 3));
		if (!dictionary->found(word))
		{
			string temp = "";
			temp = word;

			temp = substitution(word);

			if ((temp != "--"))
			{
				printw("s:%s", temp.c_str());
				return;
			}

			temp = omission(word);

			if ((temp != "--"))
			{
				printw("o:%s", temp.c_str());
				return;
			}

			temp = insertion(word);

			if ((temp != "--"))
			{
				printw("I:%s", temp.c_str());
				return;
			}
			temp = reverse(word);

			if ((temp != "--"))
			{
				printw("R:%s", temp.c_str());
				return;
			}
			if (temp == "--")
			{
				printw("wrong word:%s", temp.c_str());
				return;
			}

			// printw("  sa%s", temp.c_str());
		}
		// dictionary->DisplayInorder(dictionary->root);
	}
	string substitution(string str)
	{
		int i = 0;
		while (str[i] != '\0')
		{
			string temp = str;
			char c = 'a';
			c--;
			while (c != 'z')
			{
				c++;
				temp = str;
				temp[i] = c;
				if (dictionary->found(temp))
				{

					return temp;
				}
			}
			i++;
		}
		return "--";
	}
	void mainFunction()
	{
		string fileText = "";
		char c;
		while (1)

		{
			attron(color->getColorPair(4));
			int rows, cols;
			getmaxyx(stdscr, rows, cols); // Get screen size
			mvhline(0, 0, '-', cols);	  // Top  and bottom border
			mvhline(rows - 1, 0, '-', cols);
			mvvline(0, 0, '|', rows); // Left and right border
			mvvline(0, cols - 1, '|', rows);

			move(3, 7);
			attron(color->getColorPair(5));
			q.printQ();
			c = getch();
			clear();

			keypad(stdscr, TRUE); // Enable keypad input (if needed for special keys)

			if (c == 12)
			{ // for ctrl L
				// it loads the save .txt file in the notepad as new file opens , so it opens as a new file
				loadfile();
			}
			else if (c == 19) // ctrl + S
			{
				saveText();
			}
			else if (c == 27) // for escape
				return;
			else if (c == 7) // back space
			{
				q.deleteChar();
			}
			else
			{

				if (c == 32 || c == 10)
				{
					int x, y;
					getyx(stdscr, y, x);
					spaceOperations(x, y);
				}

				q.enqueue(char(c));
			}
		}
	}

	~NotePad()
	{
		delete dictionary;

		endwin();
	}
};
int main()
{
	NotePad npd;

	return 0;
}