#include <iostream>
#include <ctime>

int pond[9] = {0,0,0,0,0,0,0,0,0};

void fishing(){
    int n=1;
    while (true) {
        std::cout << "Let's cast a fishing rod. Which sector?" << std::endl;
        int p;
        std::cin >> p;
        if(pond[p]==1){
            throw std::runtime_error(std::to_string(n));
        }
        if(pond[p]==2){
            throw std::invalid_argument("");
        }
        std::cout << "There are no fish here" << std::endl;
        n++;
    }
}

int main() {
    std::string s = "012345678";
    std::srand(std::time(nullptr));
    int p = std::rand()%s.length();
    pond[s[p]-'0']=1;
    for(int i =0 ; i<3; i++){
        s=s.substr(0,p)+s.substr(p+1);
        p = std::rand()%s.length();
        pond[s[p]-'0']=2;
    }
    for(int i : pond){
        std::cout << " " << i ;
    }
    std::cout << std::endl;

    try {
        fishing();
    }
    catch (std::runtime_error& x){
        std::cout << "Success! You caught a fish on the "<< x.what() <<"th attempt" << std::endl;
    }
    catch (std::invalid_argument& x){
        std::cout << "Alas. You have failed" << std::endl;
    }
    return 0;
}
