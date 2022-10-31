#include "Header.h"
#include "Class.h"

/*
* @ tparam T the type of binary tree key
*/
template <class T>
class Binary_Search_Tree
{
private:
	/*
	* @Struct to represent a node in BST
	*/

	struct bst_node
	{
        T value; /**< The value/key of the node. */
        unique_ptr<bst_node> left; /**< Pointer to left subtree. */
        unique_ptr<bst_node> right; /**< Pointer to right subtree. */

        /**
        * Constructor for bst_node, used to simplify node construction and smart pointer construction.
        * @param _value The value of the constructed node.
        */
        explicit bst_node(T _value) {
            value = _value;
            left = nullptr;
            right = nullptr;
        }
	};

    /*
     * @Recursive function to insert a value into the BST.
     * @param node The node to search from.
     * @param new_value The value to insert.
     * @return true If the insert operation was successful.
     * @else return false.
     */
    unique_ptr<bst_node> root_;                 // Pointer to the root of the BST
    size_t size_ = 0;                           //Number of nodes in the BST

    bool insert(unique_ptr<bst_node>& node, T new_value) {
        if (root_ == node && !root_) {
            root_ = unique_ptr<bst_node>(new bst_node(new_value));
            return true;
        }

        if (new_value < node->value) {
            if (!node->left) {
                node->left = unique_ptr<bst_node>(new bst_node(new_value));
                return true;
            }
            else {
                return insert(node->left, new_value);
            }
        }
        else if (new_value > node->value) {
            if (!node->right) {
                node->right =
                    unique_ptr<bst_node>(new bst_node(new_value));
                return true;
            }
            else {
                return insert(node->right, new_value);
            }
        }
        else {
            return false;
        }
    }
    /*
     * @Recursive function to find the maximum value in the BST.
     * @param node The node to search from.
     * @param ret_value Variable to hold the maximum value.
     * @return true If the maximum value was successfully found.
     * @else return false.
     */
    bool find_max(std::unique_ptr<bst_node>& node, T& ret_value) {
        if (!node) {
            return false;
        }
        else if (!node->right) {
            ret_value = node->value;
            return true;
        }
        return find_max(node->right, ret_value);
    }
    /*
     * @Recursive function to remove a value from the BST.
     * @param parent The parent node of node.
     * @param node The node to search from.
     * @param rm_value The value to remove.
     * @return true If the removal operation was successful.
     * @else return false.
     */
    bool remove(unique_ptr<bst_node>& parent,
        unique_ptr<bst_node>& node, T rm_value) {
        if (!node) {
            return false;
        }

        if (node->value == rm_value) {
            if (node->left && node->right) {
                T successor_node_value{};
                find_max(node->left, successor_node_value);
                remove(root_, root_, successor_node_value);
                node->value = successor_node_value;
                return true;
            }
            else if (node->left || node->right) {
                unique_ptr<bst_node>& non_null =
                    (node->left ? node->left : node->right);

                if (node == root_) {
                    root_ = move(non_null);
                }
                else if (rm_value < parent->value) {
                    parent->left = move(non_null);
                }
                else {
                    parent->right = move(non_null);
                }

                return true;
            }
            else {
                if (node == root_) {
                    root_.reset(nullptr);
                }
                else if (rm_value < parent->value) {
                    parent->left.reset(nullptr);
                }
                else {
                    parent->right.reset(nullptr);
                }

                return true;
            }
        }
        else if (rm_value < node->value) {
            return remove(node, node->left, rm_value);
        }
        else {
            return remove(node, node->right, rm_value);
        }
    }
    /*
     * @Recursive function to check if a value is in the BST.
     * @param node The node to search from.
     * @param value The value to find.
     * @return true If the value was found in the BST.
     * @else return false.
     */
    bool contains(unique_ptr<bst_node>& node, T value) {
        if (!node) {
            return false;
        }

        if (value < node->value) {
            return contains(node->left, value);
        }
        else if (value > node->value) {
            return contains(node->right, value);
        }
        else {
            return true;
        }
    }
    /*
     * @Recursive function to traverse the tree in in-order order.
     * @param callback Function that is called when a value needs to processed.
     * @param node The node to traverse from.
     */
    void traverse_inorder(std::function<void(T)> callback,
        std::unique_ptr<bst_node>& node) {
        if (!node) {
            return;
        }

        traverse_inorder(callback, node->left);
        callback(node->value);
        traverse_inorder(callback, node->right);
    }

    /*
    * @ The public function to set up the BST from main function for BST
    */
public:
        /*
         * @Construct a new Binary Search Tree object.
         */
        void binary_search_tree() 
        {
            root_ = nullptr;
            size_ = 0;
        }

        /*
         * @Insert a new value into the BST.
         * @param new_value The value to insert into the BST.
         * @return true If the insertion was successful.
         */
        bool insert(T new_value) 
        {
            bool result = insert(root_, new_value);
            if (result) {
                size_++;
            }
            return result;
        }
        /**
        * @Find the largest value in the BST.
        * @param ret_value Variable to hold the maximum value.
        * @return true If maximum value was successfully found.
         */
        bool find_max(T& ret_value) 
        { 
            return find_max(root_, ret_value); 
        }
        /*
         * @Remove a specified value from the BST.
         * @param rm_value The value to remove.
         * @return true If the removal was successful.
         */
        bool remove(T rm_value) 
        {
            bool result = remove(root_, root_, rm_value);
            if (result) {
                size_--;
            }
            return result;
        }
        /**
        * @Check if a value is in the BST.
        * @param value The value to find.
        * @return true If value is in the BST.
        */
        bool contains(T value) 
        { 
            return contains(root_, value); 
        }
        /*
        * @Get the number of values in the BST.
        * @return size_t Number of values in the BST.
        */
        size_t size() 
        { 
            return size_; 
        }
        /*
        * @Get all values of the BST in in-order order.
        * @return vector<T> List of values, sorted in in-order order.
        */
        vector<T> get_elements_inorder() {
            vector<T> result;
            traverse_inorder([&](T node_value) {result.push_back(node_value);},root_);
            return result;
        }
};
/*
* @Function to read the information from the file and store it into the program
*/
static void insert_BST_tree()
{
    Binary_Search_Tree<Staff_Data> Staff_Infor;
}