#include"iostream"
#include <vector>
#include<stack>
#include<queue>
#include <unordered_map>
#include <memory>
#include <string>
#include <mutex>
#include "temp1.hpp"
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class TEST{
    public:
        TEST() {
            shared_ptr<int> temp(new int);
            ptr = temp;
            cout << "GOU ZAO HAN SHU:" << ptr.use_count() << endl;
        }
        ~TEST() {
            cout << "XI GOU HAN SHU" << endl;
        }
        int get_value() {
            return value;
        }
        void set_value(int a) {
            value = a;
        }
    public:
        int value = 8;
        shared_ptr<int> ptr;
};

void test(){
    TEST* ptr = new TEST();
    shared_ptr<TEST> mytest1(ptr);
    cout << mytest1.use_count() << endl;
    shared_ptr<TEST> mytest2(mytest1);
    cout << mytest2.use_count() << endl;
}
void print(char* ptr) {
    // ptr = "sssss";
    cout << ptr << endl;
}

template<typename T>

T add(T A,T B) {
    return A+B;
}

template<typename T>
T SUB(T A,T B) {
    return A-B;
}

void func(){
    TEST test1;
    cout << "test1 count is:" << test1.ptr.use_count() << endl;
    TEST test2 = test1;
    cout << "test2 count is:" << test1.ptr.use_count() << endl;
}


int main() {
    // test();
    // char* ptr;
    // ptr[0] = 'i';
    // print(ptr);
    // float ptr = add<int>(1,2.5);
    // cout << ptr << endl;
    fun(1);
    return 0;
}





///  ����������ʽʵ��  //

class SingleInstance
{

public:
    // ��ȡ��ʵ������
    static SingleInstance *GetInstance();

    //�ͷŵ�ʵ���������˳�ʱ����
    static void deleteInstance();
	
    // ��ӡʵ����ַ
    void Print();

private:
    // ���乹���������Ϊ˽�е�, ��ֹ�ⲿ���������
    SingleInstance();
    ~SingleInstance();

    // ���俽������͸�ֵ�����Ϊ˽�к���, ��ֹ�ⲿ�����͸�ֵ
    SingleInstance(const SingleInstance &);
    const SingleInstance &operator=(const SingleInstance &);

private:
    // Ψһ��ʵ������ָ��
    static SingleInstance *m_SingleInstance;
    static std::mutex m_Mutex;
};


//��ʼ����̬��Ա����
SingleInstance *SingleInstance::m_SingleInstance = nullptr;
std::mutex SingleInstance::m_Mutex;

// ע�⣺���ܷ���ָ������ã���������ⲿ���޸ĵķ��գ�
SingleInstance * SingleInstance::GetInstance()
{

    //  ����ʹ�������� if �ж����ļ�����Ϊ˫�������ô��ǣ�ֻ���ж�ָ��Ϊ�յ�ʱ��ż�����
    //  ����ÿ�ε��� GetInstance�ķ��������������Ŀ����Ͼ������е��ġ�
    if (m_SingleInstance == nullptr) 
    {
        std::unique_lock<std::mutex> lock(m_Mutex); // ����
        if (m_SingleInstance == nullptr)
        {
            m_SingleInstance = new (std::nothrow) SingleInstance();
        }
    }

    return m_SingleInstance;
}

void SingleInstance::deleteInstance()
{
    std::unique_lock<std::mutex> lock(m_Mutex); // ����
    if (m_SingleInstance)
    {
        delete m_SingleInstance;
        m_SingleInstance = nullptr;
    }
}

void SingleInstance::Print()
{
	std::cout << "�ҵ�ʵ���ڴ��ַ��:" << this << std::endl;
}

SingleInstance::SingleInstance()
{
    std::cout << "���캯��" << std::endl;
}

SingleInstance::~SingleInstance()
{
    std::cout << "��������" << std::endl;
}

void fun1(int a) {cout << a <<endl;}
void fun2(int a) {cout << a <<endl;}
void fun3(int a) {cout << a <<endl;}
void fun4(int a) {cout << a <<endl;}
void fun5(int a) {cout << a <<endl;}
using F = void (*)(int a);
F functions[5] = {
    fun1,fun2,fun3,fun4,fun5
};


// int main() {
//     for(int i = 0;i<5;i++) {
//         functions[i](i);
//     }
// }