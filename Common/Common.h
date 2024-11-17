#ifndef COMMON_H
#define COMMON_H

constexpr int MAX_SIZE = 265;
constexpr int MAX_SIZE_DATE = 11;
constexpr int INVALID_DATA = -1;
constexpr std::string BLANK_DATA = "";
constexpr std::string DOT = ".";
constexpr std::string SPECIAL_EMAIL = "@";
constexpr std::string FEMALE = "F";
constexpr std::string MALE = "M";
constexpr double PENALTY_DEFAULT_VALUE = 2;
constexpr double LATE_DEFAULT_VALUE = 5000;
constexpr double MONEY_DEFAULT_VALUE = 1000;

// Thông tin thẻ độc giả cần quản lí bao gồm: mã độc giả, họ tên, CMND, ngày tháng
// năm sinh, giới tính, email, địa chỉ, ngày lập thẻ và ngày hết hạn của thẻ (48 tháng
// kể từ ngày lập thẻ).
constexpr std::string READER_CODE = "Mã độc giả";
constexpr std::string READER_NAME = "Họ tên";
constexpr std::string READER_NATIONALID = "CMND, bắt buộc nhập 9 chữ số";
constexpr std::string READER_YEAR_BIRTHDAY = "Năm Sinh với format là YYYY";
constexpr std::string READER_SEX = "Giới tính. Nếu là Nam nhập M, nếu là Nữ Nhập F";
constexpr std::string READER_EMAIL = "Email , ví dụ a@gmail.com";
constexpr std::string READER_ADDRESS = "Địa chỉ";
constexpr std::string READER_CARD_CREATE_TIME = "Ngày lập thẻ";
constexpr std::string READER_CARD_END_TIME = "Ngày hết hạn thẻ";

// Thông tin sách cần quản lí bao gồm: ISBN (mã sách), tên sách, tác giả, nhà xuất
// bản, năm xuất bản, thể loại, giá sách, số quyển sách.
constexpr std::string BOOK_ISBN = "ISBN (mã sách)";
constexpr std::string BOOK_NAME = "Tên Sách ";
constexpr std::string BOOK_AUTHOR = "Tác giả";
constexpr std::string BOOK_PUBLISHER_EDITION = "Nhà suất bản";
constexpr std::string BOOK_YEAR_OF_PUBLICATION = "Năm suất bản với format là YYYY";
constexpr std::string BOOK_CATEGORY = "Thể loại";
constexpr std::string BOOK_PRICE = "Giá sách (*1000)";
constexpr std::string BOOK_NUMBER = "Số quyển sách";

//Mỗi phiếu mượn/trả sách chứa thông tin về mã độc giả, ngày mượn, ngày trả dự
// kiến, ngày trả thực tế và danh sách ISBN của các sách được mượn. Mỗi sách được
// mượn tối đa trong 7 ngày, nếu quá hạn sẽ bị phạt tiền 5.000 đồng/ngày. Nếu sách
// bị mất thì độc giả đó sẽ bị phạt số tiền tương ứng 200% giá sách.

constexpr std::string TRANSACTION_SLIP_READER_CODE = "Mã độc giả";
constexpr std::string TRANSACTION_SLIP_BOOK_ISBN = "Mã ISBN (mã sách)";
constexpr std::string TRANSACTION_SLIP_BORROW_DATE = "Ngày mượn";
constexpr std::string TRANSACTION_SLIP_DUE_DATE = "Ngày trả dự kiến";
constexpr std::string TRANSACTION_SLIP_ACTUAL_RETURN_DATE = "Ngày trả thực tế";
constexpr std::string TRANSACTION_SLIP_STATUS_DATE = "Trình trạng sách, Nếu vẫn còn nhập 1, Nếu mất nhập 0";
constexpr std::string TRANSACTION_SLIP_LATE_FEE = "Phí phạt quá hạn";
constexpr std::string TRANSACTION_SLIP_LATE_BOOK_PENALTY = "Phí phạt mất sách";

// Other Text
// Độc giả
constexpr std::string CHOOSE_NUMBER_OR_BACK_MENU = "chữ số để chọn chức năng. Nếu muốn quay lại menu chính, nhập -1";
constexpr std::string CHOOSE_NUMBER_OR_EXIT =
        "chữ số để tiến hành sử dụng các chức năng. Nếu muốn thoát chương trình, nhập -1";
constexpr std::string READER_CODE_EDITOR = "mã độc giả muốn sửa thông tin: ";
constexpr std::string READER_CODE_DELETE = "mã độc giả muốn xoá: ";
constexpr std::string READER_CODE_FIND_CMND = "CMND muốn tìm: ";
constexpr std::string READER_CODE_FIND_NAME = "Tên độc giả muốn tìm: ";

// Sách
constexpr std::string BOOK_CODE_EDITOR = "mã quyển sách muốn sửa thông tin";
constexpr std::string BOOK_CODE_FIND = "mã quyển sách muốn tìm";
constexpr std::string BOOK_CODE_FIND_NAME = "tên quyển sách muốn tìm";
constexpr std::string CHOOSE_NUMBER_LIST_BOOK_ISBN = "-1, Nếu muốn thoát nhập mã sách ISBN";
constexpr std::string CHOOSE_NUMBER_BORROW_BOOK_NUMBER = "số lượng sách muốn mượn";
constexpr std::string CHOOSE_NUMBER_RETURN_BOOK_NUMBER = "số lượng sách muốn trả";


// Common Function, để tạo input nhập giá trị vào cho từng title phía trên
// Dùng cho std::string
void createValue(const std::string (&title), std::string (&value));

// Dùng cho double
void createValue(const std::string (&title), double &value);

// Dùng cho int
void createValue(const std::string (&title), int &value);

// Kiêm tra giá trị chuỗi có rỗng hoặc blank không
bool isBlank(const std::string (&str));


#endif //COMMON_H
