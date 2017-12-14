#include <iostream>
int deg, dis;
std::string dir[] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

int main(void){
    std::cin >> deg >> dis;

    std::string d = dir[ ((deg*10+1125)/2250)%16 ];

    double s = ((int)((1.*dis/60)*10+0.5))/10.0;

    int W;
    if(s <= 0.2){
        d = "C";
        W = 0;
    }else{
        W = (
                s <= 1.5
                ? 1
                : s <= 3.3
                  ? 2
                  : s <= 5.4
                    ? 3
                    : s<=7.9
                      ? 4
                      : s <= 10.7
                      ? 5
                      : s <= 13.8
                        ? 6
                        : s <= 17.1
                          ? 7
                          : s <= 20.7
                            ? 8
                            : s <= 24.4
                              ? 9
                              : s <= 28.4
                                ? 10
                                : s <= 32.6
                                ? 11
                                : 12
            );
    }
    std::cout << d << " " << W << std::endl;
}
