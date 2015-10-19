--print("Hello LUA")

local old = os.time()
while true do
    local new = os.time()
    if new - old >= 1 then
        old = new
        print(old,"Hello LUA")
    end
end
