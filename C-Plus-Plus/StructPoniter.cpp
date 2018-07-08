/*
 * =====================================================================================
 *
 *       Filename:  struct_pointer.cpp
 *
 *    Description:  结构体指针
 *
 *        Version:  1.0
 *        Created:  10/03/2017 07:34:35 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Loong-Fei (Loong), urloong@163.com
 *   Organization:  zy.imau.edu.cn
 *
 * =====================================================================================
 */
#include <iostream>
#include <cstring>

using namespace std;

void printBook(struct Books *);

struct Books {
    char    title[50];
    char    author[50];
    char    subject[100];
    int     book_id;
};

int main(void)
{
    Books   book1;
    Books   book2;

    // books1详述
    strcpy(book1.title, "C++教程");
    strcpy(book1.author, "w3school");
    strcpy(book1.subject, "面向对象");
    book1.book_id = 12345;

    // books1详述
    strcpy(book2.title, "C++教程");
    strcpy(book2.author, "w3school");
    strcpy(book2.subject, "面向对象");
    book2.book_id = 12346;

    printBook(&book1);
    printBook(&book2);

    return 0;
}

void printBook(struct Books *book) {
    cout << "书籍标题: " << book->title << endl;
    cout << "书籍作者: " << book->author << endl;
    cout << "书籍类目: " << book->subject << endl;
    cout << "书籍编号: " << book->book_id << endl;
}
