#ifndef COMMON_H
#define COMMON_H

constexpr int MAX_SIZE = 265;
constexpr int MAX_SIZE_DATE = 11;
constexpr int INVALID_DATA = -1;
const std::string DOT = ".";
const std::string SPECIAL_EMAIL = "@";
const std::string FEMALE = "F";
const std::string MALE = "M";
constexpr double PENALTY_DEFAULT_VALUE = 2;
constexpr double LATE_DEFAULT_VALUE = 5000;
constexpr double MONEY_DEFAULT_VALUE = 1000;
const std::string DEFAULT_SAVE_FILE = "/Users/chukhanhhh/Desktop/Hcmus/gitLib/libFile/Document/";
const std::string DEFAULT_TYPE_FILE = "txt";

// Thông tin thẻ độc giả cần quản lí bao gồm: mã độc giả, họ tên, CMND, ngày tháng
// năm sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn của thẻ (48 tháng
// kể từ ngày lập thẻ).
const std::string READER_CODE = "Mã độc giả";
const std::string READER_NAME = "Họ tên";
const std::string READER_NATIONALID = "CMND, bắt buộc nhập 9 chữ số";
const std::string READER_YEAR_BIRTHDAY = "Năm Sinh với format là YYYY";
const std::string READER_SEX = "Giới tính. Nếu là Nam nhập M, nếu là Nữ Nhập F";
const std::string READER_EMAIL = "Email , ví dụ a@gmail.com";
const std::string READER_ADDRESS = "Địa chỉ";
const std::string READER_CARD_CREATE_TIME = "Ngày lập thẻ";
const std::string READER_CARD_END_TIME = "Ngày hết hạn thẻ";

// Thông tin sách cần quản lí bao gồm: ISBN (mã sách), tên sách, tác giả, nhà xuất
// bản, năm xuất bản, thể loại, giá sách, số quyển sách.
const std::string BOOK_ISBN = "ISBN (mã sách)";
const std::string BOOK_NAME = "Tên Sách ";
const std::string BOOK_AUTHOR = "Tác giả";
const std::string BOOK_PUBLISHER_EDITION = "Nhà suất bản";
const std::string BOOK_YEAR_OF_PUBLICATION = "Năm suất bản với format là YYYY";
const std::string BOOK_CATEGORY = "Thể loại";
const std::string BOOK_PRICE = "Giá sách (*1000)";
const std::string BOOK_NUMBER = "Số quyển sách";

//Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự
// kiến, ngày trả thực tế và danh sách ISBN của các sách được mượn. Mỗi sách được
// mượn tối đa trong 7 ngày, nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày. Nếu sách
// bị mất thì độc giả đó sẽ bị phạt số tiền tương ứng 200% giá sách.

const std::string TRANSACTION_SLIP_READER_CODE = "Mã độc giả";
const std::string TRANSACTION_SLIP_BOOK_ISBN = "Mã ISBN (mã sách)";
const std::string TRANSACTION_SLIP_BORROW_DATE = "Ngày mượn";
const std::string TRANSACTION_SLIP_DUE_DATE = "Ngày trả dự kiến";
const std::string TRANSACTION_SLIP_ACTUAL_RETURN_DATE = "Ngày trả thực tế";
const std::string TRANSACTION_SLIP_STATUS_DATE = "Trình trạng sách, Nếu vẫn còn nhập 1, Nếu mất nhập 0";
const std::string TRANSACTION_SLIP_LATE_FEE = "Phí phạt quá hạn";
const std::string TRANSACTION_SLIP_LATE_BOOK_PENALTY = "Phí phạt mất sách";

// Other Text
// Độc giả
const std::string CHOOSE_NUMBER_OR_BACK_MENU = "chữ số để chọn chức năng. Nếu muốn quay lại menu chính, nhập -1";
const std::string CHOOSE_NUMBER_OR_EXIT =
        "chữ số để tiến hành sử dụng các chức năng. Nếu muốn thoát chương trình, nhập -1";
const std::string READER_CODE_EDITOR = "mã độc giả muốn sửa thông tin: ";
const std::string READER_CODE_DELETE = "mã độc giả muốn xoá: ";
const std::string READER_CODE_FIND_CMND = "CMND muốn tìm: ";
const std::string READER_CODE_FIND_NAME = "Tên độc giả muốn tìm: ";

// Sách
const std::string BOOK_CODE_EDITOR = "mã quyển sách muốn sửa thông tin";
const std::string BOOK_CODE_FIND = "mã quyển sách muốn tìm";
const std::string BOOK_CODE_FIND_NAME = "tên quyển sách muốn tìm";
const std::string CHOOSE_NUMBER_LIST_BOOK_ISBN = "-1, Nếu muốn thoát nhập mã sách ISBN";
const std::string CHOOSE_NUMBER_BORROW_BOOK_NUMBER = "số lượng sách muốn mượn";
const std::string CHOOSE_NUMBER_RETURN_BOOK_NUMBER = "số lượng sách muốn trả";


// Common Function, để tạo input nhập giá trị vào cho từng title phía trên
// Dùng cho std::string
void createValue(const std::string (&title), std::string (&value));

// Dùng cho double
void createValue(const std::string (&title), double &value);

// Dùng cho int
void createValue(const std::string (&title), int &value);

// Kiêm tra giá trị chuỗi có rỗng hoặc blank không
bool isBlank(const std::string (&str));

// Convert String dạng số sang int
int stringToInt(const std::string &str, int start, int length);



#endif //COMMON_H
