#include"same_node.h"

bool same_node(Node n1, Node n2) {
    if (n1.name.size() <= n2.name.size()) {
        return false;
    } else {
        for (int i = 0; i < n2.name.size() - 1; i++) {
            if (n1.name[i] != n2.name[i]) {
                return false;
            }
        }
        return true;
    }
}
