# -Datastructure-HashTable
hash table practice
## 簡介：

hash table 是儲存(key,value)這種對應關係的一種資料結構，主要因為雜湊表可以在時間複雜度O(1)的狀況下進行查找，比起使用array進行搜尋的O(n)或是有經過事先排序的array O(logn)都還要快速，主要的原因就是hash function。hash table 不適合儲存有時間性的資料，這樣更適合使用queue，也不適合對hash table中的資料進行排序。

## 特性:

- 

## 構造:

key:

value:

## 儲存方式:

- 建構有初始值的has_table
    
    ```cpp
    std::unordered_map<std::string, int> m_map{
            {"0",3},
            {"1",1},
            {"2",2}};
    std::unordered_map<char, int> m_map2; //也可以無初始值
    ```
    
- 顯示目前table中數量
    
    ```cpp
    m_map.size()
    ```
    
- 印出table所有數值: 有兩種方法
    
    ```cpp
    for( const auto& m : m_map )
        {
            std::cout << "first = " << m.first << " second = " << m.second << "\n";
        }
    std::cout << "iterater =============================================\n";
    
    for( auto iter = m_map.begin(); iter != m_map.end(); iter++ )
    {
        std::cout << "iter1 = " << iter->first << " iter2 = " << iter->second << "\n";
    }
    ```
    
- 呼叫單一鍵值
    
    ```cpp
    m_map["a"];
    ```
    
- 插入鍵值
    
    ```cpp
    std::pair<std::unordered_map<std::string, int>::iterator, bool> ret;
    ret = m_map.emplace("5",10 );
    ```
    
- 刪除特定鍵值
    
    ```cpp
    m_map.erase("5");
    ```
    
- 完整範例
    
    ```cpp
    #include <iostream>
    #include <unordered_map>
    #include <string>
    
    void showTable( std::unordered_map<std::string, int> m_map );
    
    int main()
    {
        //std::unordered_map<char, int> m_map{
        //    {'5', 3},
        //    {'1',1},
        //    {'2',2}};
        std::unordered_map<std::string, int> m_map;
    
        showTable( m_map );
        
        if( m_map.empty() )
        {
            std::cout << "Empty!!!!\n";
            for( int i = 0; i < 3; i++ )
            {
                std::pair<std::unordered_map<std::string, int>::iterator, bool> ret;
                std::string s = std::to_string( i );
                std::cout << "s = " << s << "\n";
                ret = m_map.emplace( s, i + 2 );
                std::cout << "i = " << i << "\n";
                
            }
        }
        else
        {
            std::cout << "NOT Empty!!!!\n";
            std::pair<std::unordered_map<std::string, int>::iterator, bool> ret2;
            ret2 = m_map.emplace( "1", 1);
            if( !ret2.second )
            {
                std::cout << "element is exist \n";
            }
        }
        /*m_map.erase( "1");*/
        showTable( m_map );
    
        system( "PAUSE" );
        return 0;
    
    }
    
    void showTable( std::unordered_map<std::string, int> m_map )
    {
        std::cout << "all m_map number = " << m_map.size() << "\n";
        std::cout << "3 ways for reaching all element in hash table \n";
        std::cout << "for =============================================\n";
        //for( int i = 0; i < m_map.size(); i++ )
        //{
        //    std::cout << "key = " << i << " value = " << m_map[i] << "\n";
        //}
        std::cout << "for function =============================================\n";
        for( const auto& m : m_map )
        {
            std::cout << "first = " << m.first << " second = " << m.second << "\n";
        }
        std::cout << "iterater =============================================\n";
        for( auto iter = m_map.begin(); iter != m_map.end(); iter++ )
        {
            std::cout << "iter1 = " << iter->first << " iter2 = " << iter->second << "\n";
        }
    
    }
    ```