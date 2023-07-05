template<typename T>
class SqStack
{
private:
    T m_data[];
    int m_top;
    int m_len;
public:
    SqStack(int len);
    ~SqStack();
    bool Push(T x);
    T Pop();
    T& operator[](unsigned i);
    const T& operator[](unsigned i) const;
    void display() const;
};
