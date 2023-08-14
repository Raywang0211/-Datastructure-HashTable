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
        ret2 = m_map.emplace( "1", 1 );
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