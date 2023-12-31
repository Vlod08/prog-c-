# Number variant

On a un programme dont la structure s'etale sur plusieurs fichiers.

Le fichier `types.hpp` contient les types de base, le header `printing.hpp`
contient les declarations des `operator<<` pour afficher les objets definis dans
une sortie standard, `arithmetic.hpp` qui contient les declarations des
operateurs arithmetiques, et `number_factory.hpp` qui contient les declarations
relatives a la construction de ces objets a partir de chaines de caracteres.

Les definitions (CaD les implementations) sont definies dans les fichiers
sources (ie. `.cpp`) correspondants. Les headers (ie. les `.hpp`) ne contiennent
que les *declarations* de fonction, CaD les prototypes sans les corps des
fonctions.

Vous aurez besoin de la doc de `std::variant`:
https://en.cppreference.com/w/cpp/utility/variant

**Attention:** Les lambdas que vous passez a `std::visit` doivent **toujours**
renvoyer le meme type.

1.  Dans `types.hpp`, definissez `number_t` qui permet de representer soit un
    `int`, soit un `double`.

2.  Implementez un `operator<<` pour pouvoir afficher un `number_t` dans un
    `std::ostream`. Pour cela vous devrez surcharger l'`operator<<` avec la
    bonne signature, que vous trouverez dans `printing.hpp`.

3.  Implementez les operateurs arithmetiques entre `fraction_t` dans
    `arithmetic.cpp`, puis faites de meme pour `number_t`.
    Pour les operations sur des `fraction_t`, on ne demande pas que les
    fractions soient simplifiees.
    Pour les operations sur `number_t`, on se contente d'utiliser les operateurs
    arithmetiques des types contenus.

4.  Etendez `number_t` pour qu'il puisse egalement contenir un valeur de type
    `fraction_t` ou de type `std::complex<double>`.

5.  Implementez la fonction `number_factory` dans `number_factory.cpp`.
    Le premier parametre contient l'une des chaines de caracteres suivantes:
    "real", "complex", "integer", ou "fraction", et doit construire un
    `number_t` contenant une valeur du type defini a partir de la chaine de
    caracteres du 2e parametre.

    Dans le cas ou le premier parametre ne correspond a rien, renvoyez un
    `number_t` dont la valeur est celle par defaut.

    Utilisez `std::istringstream` pour la lecture des valeurs numeriques,
    les tests sont la pour lever les ambiguites sur les formats des differents
    types de valeurs.

6.  Faites des modifications a `arithmetic.cpp` et recompilez en observant quels
    fichiers sont recompiles. Quel est l'impact d'une modif de ce fichier ?
    Meme question pour `types.hpp`.
