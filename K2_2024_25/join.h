/*U zaglavlju join.h definisati šablon globalne funkcije join koja spaja vrijednosti dvije
std::map mape, prema ključu, u novu mapu. Pristupom rezultantnoj mapi po ključu dobija
se std::pair (iz <utility>) par vrijednosti pod tim ključem iz prvobitnih mapa, tj. treba da
važi join(𝑚1, 𝑚2
)[𝐾] = (𝑚1
[𝐾], 𝑚2
[𝐾]). Pretpostavlja se da obje mape imaju iste ključeve i
da se vrijednosti mogu kopirati. Primjer upotrebe:
*/
#include <map>
#include <utility>
template <typename K, typename V1, typename V2>

std::map<K, std::pair<V1, V2>> join (const std::map<K, V1>& map1, const std::map<K, V2>& map2) {
    std::map<K, std::pair<V1, V2>> temp;
    for (auto element : map1) {
        temp[element.first] = {element.second, map2.at (element.first)};
    }
    return temp;
}