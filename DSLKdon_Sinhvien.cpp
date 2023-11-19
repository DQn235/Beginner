#include <iostream>
#include <math.h>

using namespace std;

struct SinhVien {
    string Ho_ten;
    int Tuoi;
    float Diem_TB;
    int Ma_sv;
};

typedef struct SinhVien SinhVien;

SinhVien Nhap(SinhVien x)
{
    cout << "\tHo ten: ";
    cin.ignore();
    getline(cin, x.Ho_ten);
    cout << "\tTuoi: ";  cin >> x.Tuoi;
    cout << "\tDiem trung binh: ";  cin >> x.Diem_TB;
    cout << "\tMa sinh vien: ";  cin >> x.Ma_sv;
    return x;
}

struct node{
    SinhVien x;
    struct node* next;
};

node* Make_node(SinhVien x)
{
    node* Node_moi = new node();
    // C: node* Node_moi = (node*)malloc(sizeof(node));
    Node_moi -> x = Nhap(x);
    Node_moi -> next = NULL;
    return Node_moi;
}



int So_Ptu(node *head){
    int dem = 0;
    while(head != NULL){
        //Hienthi_sinhvien(head -> x);
        dem++;
        head = head -> next;
    }
    return dem;
}

void Hienthi_sinhvien(SinhVien x) {
    cout << "\t" << x.Ho_ten;
    cout << "\t\t" << x.Tuoi;
    cout << "\t" << x.Diem_TB ;
    cout << "\t\t"<< x.Ma_sv<< endl;
}

void Duyet_dsach(node *head){ //Hien thi dsach

	cout << "\tDANH SACH SINH VIEN" << endl;
	cout << "STT\tHo ten\t\tTuoi\tDiem TB\tMa sinh vien" << endl;

	//Duyet tung phan tu cua dsach va in gtri tung phan tu
	int i;
	node* tmp;
	for (tmp = head, i=1; tmp != NULL; tmp = tmp -> next){
        cout << i++;
		Hienthi_sinhvien(tmp -> x);
	}

   /*C2 while(head != NULL){ (ko can in ra STT)
        Hienthi_sinhvien(head -> x);
        cout << endl;
        head = head -> next;
    }*/
}

void Push_Front(node **head, SinhVien x){ //Them node vao dau

    node *Node_moi = Make_node(x);
    //Buoc 1: Phan next cua Node_moi => head
    Node_moi -> next = *head;
    //Buoc 2: Cap nhat node head => Node_moi
    *head = Node_moi;

}

void Push_Back(node **head, SinhVien x){ //Them vao cuoi dslk


    node *Node_moi = Make_node(x);
    if(*head == NULL){
        *head = Node_moi; return;
    }
    node *temp = *head;
    while(temp -> next != NULL){
            temp = temp -> next; //Duyet den ptu cuoi ds

        }
        //Cho phan next cua node temp -> Node_moi
        temp -> next = Node_moi;

}

void Chen(node **head, int k, SinhVien x){//Them vao vtri bat ki
      int n = So_Ptu(*head);
      if(k < 1 || k > n+1) return;

      if(k == 1){
        Push_Front(head, x);
      }

      else{
          if(k == n+1){
            Push_Back(head, x);
          }

          else{
            node *temp = *head;
            for(int i=0 ;i <= k-2; i++){
              temp = temp -> next;
            }

            node *Node_moi = Make_node(x);
            Node_moi -> next = temp -> next;
            temp -> next = Node_moi;
          }
       }
}

void Pop_Front(node **head) //Xoa Node dau
{
    if(*head == NULL) return;
    node *tmp = *head;
    *head = (*head) -> next;
    delete(tmp);
}

void Pop_Front2(node *&head) //Xoa Node dau dung tham chieu (chi trong C++)
{
    if(head == NULL) return;
    node *tmp = head;
    head = head -> next;
    delete(tmp);
}
void Pop_Back(node **head)
{
    if(*head == NULL) return;
    node *tmp = *head;
    if(tmp -> next == NULL){ // Dsach chi co 1 node
        *head = NULL;  delete(tmp);
    }
    while(tmp -> next -> next != NULL){//Duyet den ptu thu 2 tu cuoi len
        tmp = tmp -> next;
    }
    node* Node_Gancuoi = tmp -> next;//tao node moi = Node cuoi
    tmp -> next = NULL;
    delete(Node_Gancuoi);

}

void Xoa_Node(node **head, int k)// Xoa 1 vtri k bat ki
{
    int n = So_Ptu(*head);
    if (k<1 || k>n) return;
    else
    {
        if(k == 1) Pop_Front(head);
        else
        {
           if(k == n) Pop_Back(head);
           else
           {
              node* tmp = *head;
              for(int i=1; i<= k-2; i++){//Duyet den Node k-1
                 tmp = tmp -> next;
              }
              node* tmp2 = tmp -> next; //Node thu k
              //Cho k-1 => node thu k+1
              tmp -> next = tmp2 -> next;
              delete(tmp2);
        }
        }
    }



}

node* Search_Node(node *head, int Code)//Tim kiem Node
{
	//Duyet tung phan tu cua danh sach, neu co ten thi gia ve node chua ten do
	node* tmp;
	//int i;
	for (tmp = head; tmp!=NULL; tmp = tmp->next)
		if (tmp -> x.Ma_sv == Code)
			return tmp;
	return NULL;
}

void Sua_Node(node *&head, int Code){
    SinhVien a;
    if (Search_Node(head, Code) == NULL)
		cout<<"\tKhong tim thay sinh vien co ma"<<Code<<" trong danh sach\n";
	else
	{
		//Neu co sinh vien, tim vi tri sinh vien do trong danh sach
		node* tmp = Search_Node(head, Code);

		//Nhap lai du lieu cho sinh vien tren
		tmp -> x = Nhap(a);
	}
}
int main()
{
    int chon, n, position, Code;
    SinhVien sv;
    node* head = NULL;
	//char ten[20];
	do {
        cout << "1. Tao danh sach sinh vien" << endl;
        cout << "2. Hien thi danh sach sinh vien" << endl;
        cout << "3. Chen them sinh vien" << endl;
        cout << "4. Xoa mot sinh vien" << endl;
        cout << "5. Sua mot sinh vien" << endl;
        cout << "6. Sap xep sinh vien theo ten" << endl;
        cout << "7. Ket thuc" << endl;
        cout << "Chon chuc nang: ";

        cin >> chon;
        cin.ignore();

		switch (chon){
        case 1:
            cout << "\tNhap so sinh vien: "; cin>>n;
            if (n <= 0)  cout << "So sinh vien phai lon hon 0. Vui long nhap lai.";

            for (int i = 1; i <= n; i++)
            {
               cout << "\tNhap thong tin sinh vien thu " << i << endl;
               Push_Back(&head, sv);
            }
              break;

        case 2:
            Duyet_dsach(head);
            break;

        case 3:
            cout << "\tNhap vtri can chen: "; cin >> position;

            cout << "\tNhap thong tin sinh vien can them:\n";
            Chen(&head, position, sv);
            break;

        case 4:
            cout << "\tNhap vtri can xoa: "; cin >> position;
            Xoa_Node(&head, position);
            break;

        case 5:
            cout << "\tNhap ma sinh vien cua sua: "; cin >> Code;
            Sua_Node(head, Code);
            break;

        case 6:

        case 7:
            cout << "Ket thuc chuong trinh" << endl;
            break;
        default:
				cout << "\tKhong hop le" << endl;
				cout << "\tBam phim bat ky de tro ve menu\n";
				break;
		}
	} while(true);
	return 0;
}
