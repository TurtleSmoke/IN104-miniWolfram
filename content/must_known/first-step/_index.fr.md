+++
title = "Premiers pas"
pre = "<b>2. </b>"
weight = 10
+++

## Télécharger les fichiers du projet

Vous pouvez télécharger les fichiers fournis directement depuis
le [dépôt GitHub](https://github.com/TurtleSmoke/IN104.git) en utilisant la commande suivante :

```bash
git clone https://github.com/TurtleSmoke/IN104.git
```

## Créer un nouveau dépôt

Après avoir téléchargé le dépôt, la prochaine étape consiste à créer un nouveau dépôt privé sur votre compte GitHub.
Ensuite, vous devrez mettre à jour l'URL distante de votre dépôt local pour le lier avec le dépôt nouvellement créé.
Cela peut être fait en exécutant les commandes suivantes :

```bash
git remote remove origin # Supprimer l'URL distante du dépôt original
git remote add origin <new_repository_URL> # Ajouter l'URL distante du nouveau dépôt
git push -u origin main # Pousser le dépôt local vers le nouveau dépôt
```

{{% notice style="warning" %}}
Vous devez créer un dépôt privé !
{{% /notice %}}

## Ajouter des collaborateurs

Enfin, vous devrez m'ajouter ainsi que la Professeur Nguyen en tant que collaborateurs à votre dépôt. Pour ce faire,
accédez aux paramètres de votre dépôt et dans la section "Collaborateurs", cliquez sur "Ajouter des
personnes" et entrez les noms d'utilisateur suivants :

- `TurtleSmoke`
- `nguyensaomai`

{{% notice note %}}
Prévenez-moi une fois cette étape terminée !
{{% /notice %}}
