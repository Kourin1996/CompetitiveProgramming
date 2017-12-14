#include <iostream>
#include <vector>

std::vector< std::string > S(3, "");
std::vector< std::string::iterator > it(3);
std::vector< std::string::iterator > end(3);

int main(void){
    for(int i=0; i<3; ++i){
        std::cin >> S[i];
        it[i]  = S[i].begin();
        end[i] = S[i].end();
    }

    int turn = 0;
    int next = 0;
    while(true){
        turn = next;
        if(it[turn] == S[turn].end()){
            break;
        }

        next = (int)(*it[turn] - 'a');
        ++it[turn];
    }
    std::cout << (char)('A'+turn) << std::endl;
}
