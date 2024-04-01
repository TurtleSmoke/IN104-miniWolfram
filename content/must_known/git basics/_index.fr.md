+++
title = "Fondamentaux de Git"
pre = "<b>1. </b>"
weight = 5
+++

Git est un logiciel de gestion de versions décentralisé qui vous permet de suivre les changements dans votre projet. Il
est largement utilisé dans l'industrie du développement de logiciels pour gérer le code source et collaborer avec
d'autres développeurs. Une excellente ressource pour en savoir plus sur Git est
le [Livre officiel Git](https://git-scm.com/book/fr/v2).

## Initialisation

Git nécessite toujours un **dépôt** pour fonctionner. Un dépôt est une collection de fichiers et de répertoires qui
constituent un projet. Il contient l'ensemble de l'historique du projet et ses métadonnées. Fondamentalement, il s'agit
simplement d'un dossier contenant un répertoire `.git`, ce `.git` a été créé lorsque vous avez initialisé le dépôt à
l'aide de `git init`.

Si vous souhaitez commencer à utiliser Git de zéro pour un nouveau projet, vous pouvez initialiser un dépôt en exécutant
la commande `git init` dans le répertoire du projet. Cela créera un nouveau répertoire `.git`.
Ensuite, vous pouvez ajouter un nouveau dépôt distant en utilisant la commande git `remote add origin <URL du dépôt>`.
Cela liera votre dépôt local à un dépôt distant, sur GitHub par exemple. Vous pouvez également cloner un dépôt existant
à partir d'un emplacement distant en utilisant la commande `git clone <URL du dépôt>`. Cela créera un nouveau répertoire
et téléchargera tous les fichiers du dépôt distant.

Git fonctionne en versionnant les fichiers de votre projet. Ces versions sont appelés **commits**. Chaque commit
représente une version spécifique de votre projet. Vous pouvez considérer les commits comme des points de contrôle dans
l'historique de votre projet.

## Commandes de base

Comme vous pouvez le deviner, pour utiliser Git, vous devrez comprendre comment créer des commits. Mais avant de créer
un commit, vous devez indiquer à Git quels changements vous souhaitez ajouter à ce commit. Cela se fait en utilisant la
commande `git add <fichiers>`. Après avoir exécuté cette commande, Git ajoutera les modifications à la **zone de
staging**. La zone de staging est un endroit où vous pouvez préparer vos commits. Vous pouvez consulter le **statut** de
votre dépôt en utilisant la commande `git status`. Par exemple :

<div class="wrap-code highlight">
<pre>
$ echo "Ma superbe nouvelle contribution" >> mes_contributions.txt
$ echo "Ne commettons pas ça maintenant !" >> pas_maintenant.txt $ git add mes_contributions.txt
$ git status
<span style="color:gray"># Sortie de git status</span>
Sur la branche principale
Aucun commit pour le moment
Modifications à commettre :
(utilisez "git rm --cached <fichier>..." pour désindexer)
      <span style="color:green">nouveau fichier : Ma superbe nouvelle contribution</span>
Fichiers non suivis :
(utilisez "git add <fichier>..." pour inclure dans ce qui sera commité)
      <span style="color:red">pas_maintenant.txt</span>
</pre></div>

Les fichiers dans la section **Modifications à commettre** (en vert) sont les fichiers qui seront inclus dans le
prochain commit. Les fichiers dans la section **Fichiers non suivis** (en rouge) sont les fichiers qui ne sont pas
suivis par Git et ne seront pas inclus dans le prochain commit.

Si vous souhaitez créer un commit avec toutes les modifications dans la zone de staging, vous pouvez utiliser la
commande `git commit`. Vous pouvez également ajouter un message de commit en utilisant le drapeau `-m` comme
ceci : `git commit -m "Ajouter ma superbe nouvelle contribution"`.

Maintenant que vous avez créé un commit, vous pouvez afficher l'historique des commits en utilisant la
commande `git log`. Cette commande vous montrera tous les commits de votre dépôt.

Enfin, vous pouvez pousser vos commits vers un dépôt distant en utilisant la commande `git push`. Cette commande enverra
vos commits vers le dépôt distant, dans ce cas, [GitHub](https://github.com/).

Si vous souhaitez mettre à jour votre dépôt local avec les modifications du dépôt distant, vous pouvez utiliser la
commande `git pull`. Cette commande téléchargera les modifications du dépôt distant et mettra à jour votre dépôt local.

## TL;DR

Rappelez-vous que toutes les commandes git doivent être exécutées dans le répertoire de votre projet.

```shell
# Initialiser un nouveau dépôt pour un nouveau projet
git init 
git remote add origin <URL du dépôt> 
# Ou cloner un dépôt existant
git clone <URL du dépôt>

# Faire des modifications à vos fichiers
touch "Ma superbe nouvelle contribution" >> mes_contributions.txt

# Ajouter les modifications à la zone de staging
git add mes_contributions.txt

# Vérifier le statut de votre dépôt
git status

# Créer un commit à partir des modifications dans la zone de staging
git commit -m "Ajouter ma superbe nouvelle contribution"

# Vous pouvez vérifier l'historique des commits
git log

# Pousser le commit vers le dépôt distant
git push

# Vos collaborateurs devront tirer les modifications
git pull
```