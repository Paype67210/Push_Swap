<picture>
<img alt="Entête du dépôt ft_push_swap." src="https://github.com/Paype67210/Push_Swap/blob/main/Tools/cover-push_swap.png">
</picture>

### Objectifs du projet

- **Trier une pile d'entiers** en utilisant un ensemble de commandes simples pour déplacer les éléments entre deux piles.
- **Optimiser les opérations** en réduisant le nombre total de mouvements effectués.
- **Implémenter des algorithmes de tri efficaces** : Ce projet demande de concevoir des algorithmes spécifiques pour différents volumes de données, et notamment d'optimiser le tri sur des petits ensembles (3, 5, 100, ou 500 éléments).

### Compétences acquises

- **Conception d'algorithmes de tri** : Le projet introduit des techniques de tri personnalisées comme le tri par insertion et d'autres stratégies adaptées aux contraintes spécifiques des piles.
- **Gestion de la complexité algorithmique** : Il s'agit de comprendre et d'appliquer des concepts d'optimisation pour améliorer l'efficacité de l'algorithme en termes de temps d'exécution et de nombre d'instructions.
- **Manipulation de données sur des piles** : Utilisation de structures de données comme les piles et gestion des opérations élémentaires telles que :
  - `sa` : Swap les deux premiers éléments de la pile A.
  - `sb` : Swap les deux premiers éléments de la pile B.
  - `pa` : Pousse le premier élément de la pile B sur la pile A.
  - `pb` : Pousse le premier élément de la pile A sur la pile B.
  - `ra`, `rb` : Fait tourner la pile vers le haut.
  - `rra`, `rrb` : Fait tourner la pile vers le bas.

### Détails techniques et stratégies

- **Tri pour des petits ensembles (3 à 5 éléments)** : Le projet demande d'implémenter des algorithmes spécifiques et très optimisés pour trier de très petits ensembles en un nombre minimal d'instructions.
- **Tri pour des ensembles plus grands (100 à 500 éléments)** : Pour des piles de taille plus importante, il est nécessaire d'implémenter des stratégies de tri plus complexes, comme le tri par radix ou des variantes optimisées du tri par insertion.
- **Analyse de la complexité temporelle** : Évaluation de l'efficacité de l'algorithme en fonction du nombre d'éléments, en visant à réduire le nombre d'instructions à exécuter.

### Bonus : Création d'un Checker

Une partie bonus du projet consiste à développer un **checker** qui valide le bon fonctionnement de l'algorithme de tri. Ce programme prend en entrée la sortie générée par le programme **Push_Swap** et vérifie si les instructions appliquées sur la pile aboutissent réellement à un tri complet des éléments. Le **checker** compare l'état final de la pile avec l'ordre attendu et retourne si le tri est effectivement correct. Cela permet d'assurer que l'algorithme non seulement fonctionne, mais qu'il respecte également les contraintes définies par le projet en termes de mouvements et de résultat.

### Possibilités d'amélioration

Le projet **Push_Swap** peut être enrichi de plusieurs manières :
- **Amélioration des algorithmes** : Étude d'algorithmes plus avancés, tels que le tri rapide (quicksort) ou le tri par fusion (mergesort), et adaptation de ces algorithmes aux contraintes de Push_Swap.
- **Visualisation des opérations** : Ajout d'une interface graphique ou textuelle pour visualiser en temps réel les mouvements entre les deux piles, afin de mieux comprendre et déboguer l'algorithme.
- **Analyse de performance** : Intégrer une fonction qui calcule le nombre d'opérations utilisées pour chaque tri et compare les performances des différents algorithmes.

### Conclusion

Le projet **Push_Swap** est une excellente opportunité d'approfondir ses connaissances en algorithmie, notamment en matière de tri et d'optimisation. Il met l'accent sur la conception et la mise en œuvre de solutions efficaces pour des problèmes de tri, tout en travaillant avec des structures de données comme les piles et en respectant des contraintes spécifiques. Le bonus avec le **checker** permet de garantir la validité du tri et d'ajouter une dimension supplémentaire à l'évaluation des performances de l'algorithme.

### Ressources supplémentaires

- [Introduction aux algorithmes de tri](https://www.geeksforgeeks.org/sorting-algorithms/)
- [Tutoriel sur la complexité algorithmique](https://www.bigocheatsheet.com/)

