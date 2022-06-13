local path = '/sdcard/Notes/kamVdta.key'
local file = io.open(path, "rb")
pcall(load(gg.makeRequest('http://sub.kamvdta.xyz:8888/down/oASmXzgJbkqo').content))

function start()
if not file then
    local Menu = gg.prompt({"Vui lòng nhập mã kích hoạt của bạn: "},nil,{"text"})
    if not Menu then return end
    loader(Menu[1])
else
    local content = file:read 
    "*a"
    file:close()
    loader(content)
end
end

function loader(key) 
    API = gg.makeRequest(ZGVjb2Rl('aHR0cDovL3N1Yi5rYW12ZHRhLnh5ejo4ODg4L2Rvd24v') .. key).content
    if not API then
      gg.toast('📛 Mã kích hoạt không đúng!')
      os.remove(path)
    else
      local data = io.open(path,'w')
      data:write(key)
      data:close()
      gg.alert(os.date("➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n\n                                       Thời Gian Hiện Tại\n\n                    Ngày: %d/%m/%Y            Giờ:  %H:%M:%S\n\n➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖\n\n                      :::::                      Thông báo                    :::::\n\n+ Combo: Hack Liên Quân + Mạng 4G 500Gb/tháng chỉ 15k\n+ Hỗ trợ tải miễn phí khi mua gói (V2ray/Shadowrocket)\n+ 40 server Việt bao chiến Liên Quân\n+ 10 server ngoại bao mượt hơn 1.1.1.1\n\n+ Zalo: 0345785426 (Inbox)\n\n                                              --- kamVdta ---\n\n➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖➖"), "< Chiến nào >")
      pcall(load(gg.makeRequest(ZGVjb2Rl(gg.makeRequest(ZGVjb2Rl('aHR0cDovL3N1Yi5rYW12ZHRhLnh5ejo4ODg4L2Rvd24vWVU5OXFzV25vaDd0')).content)).content))
    end
end

start()