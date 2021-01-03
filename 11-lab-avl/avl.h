#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
#define max(a, b) \
	({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

struct Node
{
	int data;
	struct Node *left_child;
	struct Node *right_child;
	int height;
};

/* өгөгдсөн data утга бүхий шинэ Node үүсгэж буцаана */
struct Node *create_node(int data)
{
	struct Node *n = (struct Node *)malloc(sizeof(struct Node));
	n->data = data;
	n->left_child = NULL;
	n->right_child = NULL;
	n->height = 1;
	return n;
}
/* өгөгдсөн дэд модыг устгах */
void delete_tree(struct Node *n)
{
	if (n != NULL)
	{
		delete_tree(n->left_child);
		delete_tree(n->right_child);
		free(n);
		n = NULL;
	}
}

/* root-ийн зааж буй дэд модноос x тоог хайн, олдсон node-ийн хаягийг буцаана.
   Олдохгүй бол null утгыг буцаана.
 */
struct Node *find(struct Node *root, int d)
{
	//Байхгүй эсвэл олсон тохиолдолд дуусгана
	if (root == NULL || d == root->data)
		return root;
	//Хэрэв гараас оруулсан дата нь root ээс их байвал баруун хүү рүү recurvise -аар явна
	if (d > root->data)
		return find(root->right_child, d);
	//Эсрэг тохиолдолд
	else
		return find(root->left_child, d);
}
/* root-ийн зааж буй зангилаагаар үндсээ хийсэн модны өндрийг буцаана */
int height(struct Node *root)
{
	//Хэрвээ root нь NULL тэй тэнцвэл хоосон эсвэл дууссан гэсэн үг
	if (root == NULL)
		return 0;
	return root->height;

	// return (1 + max(height(root->left_child), height(root->right_child)));
}

int checkProperty(struct Node *root)
{
	if (root == NULL)
		return 0;
	return height(root->left_child) - height(root->right_child);
}

struct Node *rightRotate(struct Node *right)
{
	struct Node *left = right->left_child;
	struct Node *left_right = left->right_child;

	left->right_child = right;
	right->left_child = left_right;

	//Өндрөө шинэчлэнэ
	right->height = 1 + max(height(right->left_child), height(right->right_child));
	left->height = 1 + max(height(left->left_child), height(left->right_child));

	return left;
}

struct Node *leftRotate(struct Node *left)
{
	struct Node *right = left->right_child;
	struct Node *right_left = right->left_child;

	right->left_child = left;
	left->right_child = right_left;

	//Өндрөө нэмж өгнө
	left->height = 1 + max(height(left->left_child), height(left->right_child));
	right->height = 1 + max(height(right->left_child), height(right->right_child));

	return left;
}

/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модонд d утгыг орууж шинээр үүссэн дэд модыг буцаана */
struct Node *
insert(struct Node *root, int d)
{
	//Хоосон гэж үзээд гараас орж ирсэн дататай шинэ Node үүсгэнэ
	if (root == NULL)
		return create_node(d);
	//Гараас орж ирсэн дата (key) нь root -с бага тохиолдолд зүүн хүү рүү орно
	if (d < root->data)
		root->left_child = insert(root->left_child, d);
	//Дээд мөрны эсрэг тохиолдолд
	else if (d > root->data)
		root->right_child = insert(root->right_child, d);
	//Уг функц маань node төрлийн утгыг буцаах хэрэгтэй учир заавал бичих шаардлагатай
	else
		return root;

	root->height = 1 + max(height(root->left_child), height(root->right_child));

	int property = checkProperty(root);

	//4 чанарыг шалгаж үзээд тэнцвэрт модыг хэрэгжүүлнэ

	//LL case
	if (property > 1 && d < root->left_child->data)
		return rightRotate(root);

	//LR case
	if (property > 1 && d > root->left_child->data)
	{
		root->left_child = leftRotate(root->left_child);
		return rightRotate(root);
	}

	//RR case
	if (property < -1 && d > root->right_child->data)
		return leftRotate(root);

	//RL case
	if (property < -1 && d < root->right_child->data)
	{
		root->right_child = rightRotate(root->right_child);
		return leftRotate(root);
	}
}
/* root-ийн зааж буй зангилаагаар үндэсээ хийсэн дэд модоос d утгыг устгаж шинээр үүссэн дэд модыг буцаана */
struct Node *remove1(struct Node *root, int d)
{
	//Recursive функц дуусах нөхцөл
	if (root == NULL)
		return root;

	//Гараас оруулсан датаг root-н дататай жишнэ
	//Хэрвээ бага байвал зүүн хүү рүү recursive-р цааш үргэлжлүүлэн
	//жишнэ
	if (d < root->data)
		root->left_child = remove1(root->left_child, d);
	//Эсрэг тохиолдолд
	else if (d > root->data)
		root->right_child = remove1(root->right_child, d);
	//Дээрх 2 нөхцөлийг алгасаж энд хүрч ирвэл
	//Устгах гэж буй датаг олсон гэсэн үг
	//Тиймд цааш устгах үйлдлээ үргэлжлүүлнэ.
	//BST Tree дээр устгах 3 нөхцөл бий
	//1. Leaf node, 2. 1 child, 3. 2 children
	else
	{
		//Баруун эсвэл зүү хүүгийн аль нэг нь NULL тэй тэнцүү байвал
		//1 child эсвэх leaf node гэж үзнэ
		if (root->left_child == NULL)
		{
			struct Node *temp_node = root->right_child;
			free(root);
			return temp_node;
		}
		else if (root->right_child == NULL)
		{
			struct Node *temp_node = root->left_child;
			free(root);
			return temp_node;
		}

		//2 children тай тохиолдолд
		//Баруун дэд модны хамгийн багыг олоод датаг нь temp_node дотор хадгална
		struct Node *temp_node = root->right_child;
		while (temp_node->left_child != NULL)
			temp_node = temp_node->left_child;

		//Хадгалж авсан датагаа устгах гэж буй node тэйгоо солино
		root->data = temp_node->data;
		//Subtree -г уламжлуулна
		root->right_child = remove1(root->right_child, root->data);
	}
	return root;
}
/* root-ийн зааж буй Tree-г in-order-оор хэвлэ */
void inorder(struct Node *root)
{
	//ТОДОРХОЙЛОЛТ: inorder traversal дээр left - root - right гэсэн
	//дүрмээр явна
	if (root == 0)
		return;
	inorder(root->left_child); //left
	printf("%d, ", root->data);
	inorder(root->right_child); //right
}
#endif
