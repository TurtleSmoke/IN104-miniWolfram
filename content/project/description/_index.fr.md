+++
title = "Description"
pre = "<b>1. </b>"
weight = 10
+++

{{% notice note %}}
Avant de commencer le projet, veuillez suivre les instructions dans les [premiers pas](project/first-step) pour
télécharger les fichiers fournis
et créer un nouveau dépôt.
{{% /notice %}}

## Aperçu

Le projet consiste à créer une version simplifiée de [Wolfram Alpha](https://www.wolframalpha.com/) en commençant par
l'implémentation d'une calculatrice de base. Cette calculatrice doit être capable de gérer les opérations suivantes :

- Addition
- Soustraction
- Multiplication
- Division
- Modulo

De plus, la calculatrice doit pouvoir gérer les parenthèses et les espaces au sein des expressions.

Votre exécutable doit être nommé `miniWolfram` et doit accepter une expression mathématique en tant qu'argument par
ligne de commande.
Lors de l'exécution, le programme doit évaluer l'expression et afficher le résultat sur la sortie standard. Tout message
d'erreur
doit être affiché sur la sortie d'erreur standard.

Voici des exemples illustrant le comportement attendu du programme :

```shell
./miniWolfram "1 + 1"
2

./miniWolfram "1 + 2 * 3"
7

./miniWolfram "(1 + 2) * 3"
9

./miniWolfram "1       + 1"
2
```

{{% notice note %}}
Le code fourni inclut des fonctions utiles pour vous aider à démarrer. Veuillez vous référer
à [ce lien](project/given-code)
pour plus de détails.
{{% /notice %}}

## Directives du projet

Le projet est divisé en trois parties :

- [Analyse lexicale](#analyse-lexicale)
- [Analyse syntaxique](#analyse-syntaxique)
- [Évaluation](#évaluation)

Chaque partie est décrite en détail dans les sections suivantes.

### Analyse lexicale

L'analyse lexicale est la première étape du projet. Elle convertit la chaîne de caractères d'entrée en une séquence de
jetons, où chaque jeton représente un élément unique de la chaîne d'entrée, tel qu'un nombre, un opérateur ou une
parenthèse. Cette étape comprend également la détection des jetons invalides tels que les lettres ou les caractères
spéciaux.

Cette étape vous permet par la suite de vous concentrer sur la syntaxe et l'évaluation de l'expression sans vous soucier
de la validité de la chaîne de caractères en entrée.

### Analyse syntaxique

L'analyse syntaxique est la deuxième étape du projet. Elle convertit une séquence de jetons en une expression en
notation polonaise inverse (NPI).
Ce processus comprend également la détection d'expressions invalides telles que les opérateurs ou les opérandes
manquants.

La [notation polonaise inverse](https://en.wikipedia.org/wiki/Reverse_Polish_notation) est une notation mathématique
dans laquelle
chaque opérateur suit tous ses opérandes, elle élimine l'ambiguïté de la priorité des opérations dans la notation
couramment utilisée
(appelée notation infixe). Elle facilite l'évaluation de l'expression et supprime le besoin de parenthèses.
Par exemple, l'expression `1 + 2 * 3` est représentée par l'expression NPI suivante : `1 2 3 * +`.

Vous êtes libre d'utiliser n'importe quel algorithme pour convertir l'expression infixée en NPI, mais il est conseillé
d'utiliser
l'[algorithme de Shunting-yard](https://en.wikipedia.org/wiki/Shunting-yard_algorithm), car le pseudo-code est fourni
dans la
page Wikipédia et peut être facilement adapté à vos besoins.

### Évaluation

L'évaluation est la dernière étape du projet. Elle consiste à évaluer l'expression NPI résultant de l'analyse
syntaxique. L'expression NPI peut être visualisée comme un arbre binaire, où les feuilles sont les nombres et les nœuds
internes
sont les opérateurs. En utilisant l'expression NPI précédente comme exemple, nous obtenons l'arbre binaire suivant :

{{< mermaid >}}
graph TD
A((+)) --> B((1))
A --> C((*))
C --> D((2))
C --> E((3))
{{< /mermaid >}}

Cet arbre peut être évalué en utilisant
le [parcours post-ordre](https://en.wikipedia.org/wiki/Tree_traversal#Post-order,_LRN).
Vous êtes libre d'utiliser n'importe quel algorithme pour évaluer l'expression NPI, que ce soit un algorithme récursif,
basé sur une pile ou
basé sur un arbre.

### Pour aller plus loin

Une fois que la calculatrice de base est opérationnelle, vous êtes encouragé à l'améliorer en intégrant des
fonctionnalités supplémentaires de votre
choix. Voici quelques exemples de fonctionnalités supplémentaires, mais vous êtes invité à proposer vos propres idées :

- Fonctions (sin, cos, tan, log, etc.)
- Constantes (pi, e, etc.)
- Variables, y compris la capacité de stocker et de récupérer des valeurs
- Interface graphique
- Résolution pas à pas
- Résolution d'équations (linéaires, quadratiques, etc.)
- Tracé de graphiques à partir d'équations linéaires ou quadratiques
- Intégration et dérivation
- Calculs de matrices
- Gestion des nombres complexes
- Gestion d'un nombre infini de jetons

## Aperçu du projet

Comme une image vaut mieux que mille mots, voici un aperçu de l'entrée et de la sortie de chaque étape du projet :

![Aperçu du projet](overview.png?width=100%^&height=100%)
