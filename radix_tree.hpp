#include <string>
#include <map>
#include <algorithm>
#include <memory>
#include <vector>


class node
{
public:

    explicit node(const std::string& str, const int& _is_end):label(str),is_end(_is_end){}

    void add(const std::string& value)
    {
         auto matcher = std::mismatch(label.begin(),label.end(),value.begin(),value.end());

         //!< вставка узла
         if (matcher.first != label.end())
         {
             this->label = std::string(label.begin(),matcher.first);
             auto paste_node = std::make_unique<node>(std::string(matcher.first,label.end()),1);
             for (auto& it : childs)
             {
                 paste_node->childs[it.first] = std::move(it.second);
             }
             childs.clear();
             childs[*matcher.first] = std::move(paste_node);
         }

         //!< добавление child в текущем узле
         if (matcher.second != value.end())
         {
             auto it = childs.find(*matcher.second);
             if (it == childs.end())
             {
                 childs[*matcher.second] = std::make_unique<node>(std::string(matcher.second,value.end()),1);
             }
             else
             {
                 childs[it->first]->add(std::string(matcher.second,value.end()));
             }
         }
    }

    

    auto empty()
    {
        return childs.size() == 0;
    }

    void print_childs(std::string &separator)
    {
        
    }
private:
    std::map<char,std::unique_ptr<node>> childs;
    std::string label;
    int is_end;

   

    
};

class radix_tree
{
public:
    radix_tree(){};
    ~radix_tree(){};

    void add(std::string & other)
    {
        static int node_initialisation = 0;
        if (!node_initialisation)
        {
             node_initialisation = 1;
             root = std::make_unique<node>(other,1);
             return;
        }
        root->add(other);
    }

    void get_info()
    {
      
    }

private: 
    std::unique_ptr<node> root; //!<god node;
};



