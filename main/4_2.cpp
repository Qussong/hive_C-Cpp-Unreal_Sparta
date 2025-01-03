
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

class Book;
class BookManager;
class BorrowManager;

int main()
{
    BookManager manager;
    BorrowManager manager2;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true)
    {
        std::cout << "\n������ ���� ���α׷�" << std::endl;
        std::cout << "1. å �߰�" << std::endl;         // å ������ �Է¹޾� å ��Ͽ� �߰�
        std::cout << "2. ��� å ���" << std::endl;    // ���� å ��Ͽ� �ִ� ��� å ���
        std::cout << "3. ����" << std::endl;            // ���α׷� ����
        std::cout << "4. �˻�" << std::endl;  // å �˻�
        std::cout << "����: ";

        int choice; // ������� �޴� ������ ����
        std::cin >> choice;

        if (choice == 1)
        {
            // 1�� ����: å �߰�
            // ����ڷκ��� å ����� ���ڸ��� �Է¹޾� BookManager�� �߰��մϴ�.
            std::string title, author;
            std::cout << "å ����: ";
            std::cin.ignore(); // ���� �Է��� �ܿ� ���۸� ����
            getline(std::cin, title); // ���� �Է� (���� ����)
            std::cout << "å ����: ";
            getline(std::cin, author); // ���ڸ� �Է� (���� ����)
            manager.addBook(title, author); // �Է¹��� å ������ �߰�
        }
        else if (choice == 2)
        {
            // 2�� ����: ��� å ���
            // ���� BookManager�� ����� å ����� ����մϴ�.
            manager.displayAllBooks();
        }
        else if (choice == 3)
        {
            // 3�� ����: ����
            // ���α׷��� �����ϰ� ����ڿ��� �޽����� ����մϴ�.
            std::cout << "���α׷��� �����մϴ�." << std::endl;
            break; // while ���� ����
        }
        else if (choice == 4)
        {
            int option = -1;
            std::string input = "";
            // 4�� ����: �˻�
            std::cout << "�˻������� �������ּ��� (1:å����, 2:�۰�) : ";
            std::cin >> option;
            std::cout << "�˻� : ";
            std::cin >> input;
            manager.searchBook(option, input);
        }
        else
        {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            std::cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << std::endl;
        }
    }
}

class Book
{
public:
    std::string title;
    std::string author;

    Book(const std::string& title, const std::string& author)
        : title(title), author(author) {}
};

class BookManager
{
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author);
    void displayAllBooks() const;
    void searchBook(int option, std::string input) const;
};

#pragma region BookManager

void BookManager::addBook(const std::string& title, const std::string& author)
{
    books.push_back(Book(title, author)); // push_back ���
    std::cout << "å�� �߰��Ǿ����ϴ�: " << title << " by " << author << std::endl;
}

void BookManager::displayAllBooks() const
{
    if (books.empty())
    {
        std::cout << "���� ��ϵ� å�� �����ϴ�." << std::endl;
        return;
    }

    std::cout << "���� ���� ���:" << std::endl;
    // �Ϲ����� for�� ���
    for (size_t i = 0; i < books.size(); i++)
    {
        std::cout << "- " << books[i].title << " by " << books[i].author << std::endl;
    }
}

void BookManager::searchBook(int option, std::string input) const
{
    // option 1 : å ���� �˻�
    // option 2 : �۰� �˻�

    for (int i = 0; i < books.size(); ++i)
    {
        // å ���� �˻�
        if (1 == option)
        {
            if (books[i].title == input)
            {
                std::cout << "- " << books[i].title << " by " << books[i].author << std::endl;
                return;
            }
        }
        // �۰� �˻�
        else if (2 == option)
        {
            if (books[i].author == input)
            {
                std::cout << "- " << books[i].title << " by " << books[i].author << std::endl;
                return;
            }
        }
    }

    std::cout << "�Է��Ͻ� ������ å�� ã�� �� �����ϴ�." << std::endl;
}

#pragma endregion

class BorrowManager
{
public:
	void initializeStock(std::vector<Book> books, int _quantity = 3);
	void borrowBook(std::string& title);    // å ������
	void returnBook(std::string& book);     // å �ݳ��ϱ�
	void displayStock();                    // å ��� Ȯ���ϱ�
private:
	std::unordered_map<std::string, int> stock;
};

#pragma region BorrowManager

void BorrowManager::initializeStock(std::vector<Book> books, int _quantity)
{

}

void BorrowManager::borrowBook(std::string& title)
{

}

void BorrowManager::returnBook(std::string& book)
{

}

void BorrowManager::displayStock()
{

}

#pragma endregion
