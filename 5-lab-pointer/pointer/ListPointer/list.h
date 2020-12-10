#ifndef HEADER_FILE
#define HEADER_FILE
#include <stdlib.h>
struct Node
{
	int data;
	struct Node *next;
};

struct List
{
	struct Node *root;
};
int error = 0, size = 0;

const char error_msg[][50] = {
	"",
	"List xooson!",
	"Bairlald oruulax bolomjgui!",
	"Bairlaas gargax bolomjgui!"};
void init(struct List *p, int n)
{
	p->root = NULL;
}

void release(struct List *p)
{
	free(p->root);
	p->root = NULL;
}
/* p-ийн зааж буй List хоосон бол 1 үгүй бол 0-ийг буцаана */
int empty(struct List *p)
{
	/* Энд хоосон эсэхийг шалгах үйлдлийг хийнэ */
	return p->root == NULL ? 1 : 0;
}

/* p-ийн зааж буй List-д x утгыг pos байрлалд хийнэ
   pos болон түүнээс хойшхи элементүүд нэг байрлал ухарна.
 */
void insert(struct List *p, int x, int pos)
{
	/* Энд оруулах үйлдлийг хийнэ үү */
	struct Node *new = (struct Node *)malloc(sizeof(struct Node)); // шинэ Node бэлдэнэ
	new->data = x;												   // Бэлдсэн шинэ node дээр гараас оруулсан утгыг нь хадгална

	// Хэрвээ листийн 0 байрлал дээр утга нэмвэл хойно
	// байгаа бүх node-г shift үйлдлээр байрлалыг эзлүүлнэ
	if (pos == 0)
	{
		//Шинэ Node-н next хэсэгт листийн эхлэлийг хадгална
		new->next = p->root;
		//Листийн эхлэлийн Node-д шинэ Node-г хадгална
		p->root = new;
		// Ингэснээр шинэ node-г листийн эхлэл болгож хуучин root
		// буюу листийн эхлэл node-н хаягийг шинэ node-н next дээр хадгална
	}

	//Хэрвээ лист хоосон байвал шинэ node-г листийн эхлэл болгоно.
	else if (p->root == NULL)
	{
		p->root = new;
		//Листийн төгсгөлийн node-н next хэсэг үргэлж NULL утгыг заана
		new->next = NULL;
	}
	else
	{
		//Бусад тохиолдолд жагсаалтад утга оруулах үйлдэл энд хийгдэнэ
		struct Node *temp = p->root;

		//Гараас орж ирсэн pos байрлалын өмнөх Node-н утгыг temp -д хадгалах зорилготой.
		for (int i = 1; i < pos; i++)
		{
			//хамгийн хол явах index нь
			//NULL утга таартал буюу жагсаалтын төгсгөл хүртэл явах боломжтой
			//Тийм учир жагсаалтад гараас оруулах утгын байрлалыг аваад
			//утга оруулахад оруулах байрлал нийт жагсаалтын элементээс
			//их байвал хамгийн сүүлд нь ороод явна. Өмнөх Array аргаар үүсгэсэн
			//List-н "хэмжээ дүүрсэн" гэдэг алдааг гаргах шаардлагагүй
			if (temp->next != NULL)
				temp = temp->next; //temp node дээр дараагийн node-г хадгална
		}

		//Зорисондоо хүрсэн тул оруулах гэж буй байрлалд байгаа node-н
		//хаягийг шинэ node-доо хадгална. Тухайн хаягийг pos байрлалын өмнөх
		//node хадгалж байгаа учраас уг үйлдлийг хийж байгаа
		new->next = temp->next;
		//Одоо нэг хаягийг хоёр газар хадгалсан байгаа тул хуучин node доо
		//шинээр орж ирсэн node-н хаягийг оноож өгнө.
		temp->next = new;
		//Ингэснээр жагсаалтад гараас утга оруулах үйлдэл амжилттай болж байна
	}
}

/* p-ийн зааж буй List-н pos байралаас гарган буцаана.
   pos болон түүнээс хойшхи элементүүд нэг байрлал урагшилна.
 */
int removes(struct List *p, int pos)
{
	/* Энд гаргах үйлдлийг хийнэ үү */

	if (p->root == NULL)
		return error = 1;
	else if (pos == 0)
	{
		// ↑ Хэрвээ эхний байрлалыг устгах гэж байгаа бол ажиллана

		//Хэд гэсэн утгыг устгаснаа буцааж харуулах учир temp гэсэн integer
		//төрлийн хувьсагч зарлана
		int temp;
		//тухайн хувьсагчдаа устгах гэж байгаа утгыг хадгална
		temp = p->root->data;
		free(p->root); //Санах ойгоос чөлөөлөх функц
		//Жагсаалтын эхлэлийг хоёр дох node-р эхлүүлнэ
		p->root = p->root->next;
		return temp;
	}
	else
	{
		struct Node *index = p->root;
		//Өмнөх insert -тай адил зорилготой давталт
		for (int i = 1; i < pos; i++)
		{
			if (index->next != NULL)
				index = index->next;
			else
				//Хэрвээ жагсаалтын нийт уртаас их утга гараас орж ирвэл
				//3 индекстэй error мессежийг буцаана
				return error = 3;
		}

		//Ямар утга устгаснаа return хийж буцаах учир шинэ node үүсгэж устгах node-нхоо
		//утгыг хадгална
		struct Node *removed_node = index->next;

		//[23:0x001][15:0x002][42:NULL] гэсэн жагсаалт байлаа гэж үзэхэд "0" байрлалд
		//байгаа node-д "2" байрлалын node-н хаягийг нь зааж өгнө. Ингэснээр голын node
		//жагсаалтаас хасагдаж байна
		index->next = index->next->next;
		int temp = removed_node->data; //Устгах гэж буй node-н датаг хадгална
		free(removed_node);			   //Санах ойгоос чөлөөлнө
		return temp;
	}

	// index->next = index->next->next;
}
/* p-ийн зааж буй List-н утгуудыг хэвлэнэ */
void print(struct List *p)
{
	/* Энд хэвлэх үйлдлийг хийнэ үү */

	struct Node *index;
	index = p->root;
	printf("\nLinked List:\n");
	for (int i = 0;; i++)
	{
		if (index == NULL)
			break;
		printf(" %d. %d\n", i, index->data);
		index = index->next;
	}
	printf("\n===========\n");
}
/* p-ийн зааж буй List-с x тоог хайн олдсон байрлалаыг буцаана.
   Олдохгүй бол -1 утгыг буцаана.
 */
int find(struct List *p, int x)
{
	//Жагсаалт хоосон тохиолдолд
	if (p->root == NULL)
		return error = 1;

	//Бусад тохиолдолд
	struct Node *index = p->root;
	int i = 0;
	while (index != NULL)
	{
		if (index->data == x)
			return i;		 //Утга олдвол i байрлалыг буцаана
		index = index->next; // Үгүй тохиолдолд дараагийн node-рүү шилжинэ
		i++;
	}
	return -1;
}

#endif
