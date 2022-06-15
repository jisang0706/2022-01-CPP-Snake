# 2022-01-cpp-snake
### attribute

|access modifier|type|name||
|--|--|--|--|
|protected|Window*|window|상속받는 객체들이 각자 제어할 윈도우|

### method

|access modifier|return|name||
|--|--|--|--|
|public|void|Render()|윈도우에 각각 렌더링 처리를 해 줄 가상함수|
|private|void|EraseWindow(Window* window)|윈도우를 지우고 해제하는 함수|
|public||~Renderable()|소멸자

## SnakeGame
### method
|access modifier|return|name||
|--|--|--|--|
|public|int|main()|게임 실행|

## Kbhit
### method
|access modifier|return|name||
|--|--|--|--|
|public|int|kbhit()|사용자가 키보드를 제어중인지 확인|

## NCursesSetting
### method
|access modifier|return|name||
|--|--|--|--|
|public|void|NcursesSeting()|Ncurses 관련 설정|

## GameFlow
### attribute
|access modifier|type|name||
|--|--|--|--|
|private|char|text[400]|

### method
|access modifier|return|name||
|--|--|--|--|
|public|GameFlow()
|public|int|InfoStartMenu()|게임 선택 창|
|public|void|InfoMakers()|제작자들 렌더링|
|public|void|InfoGameEnd()|게임 종료 시 프롬프트|
|public|int|InfoStageEnter(const int stage)|게임 진입 시|
|public|int|InfoStageClear(const int stage)|클리어 시|
|private|void|EraseWindow(WINDOW* window)|윈도우 지우고 해제|

## Game

### attribute
|access modifier|type|name||
|--|--|--|--|
|public|bool|is_clear|mission 클리어 판단|
|public|bool|isValid|유효성검사|
|public|int|key|사용자 입력값|
|private|int|game_stage|스테이지 번호|
|private|Snake*|player|해당 스테이지의 플레이어(뱀)|
|private|GameData*|game_data|해당 스테이지의 게임데이터|
|private|userData*|user_data|해당 스테이지의 플레이 정보|
|private|ItemManager*|item_manager|해당 스테이지의 아이템 관리자|
|private|Mission*|mission|해당 스테이지의 미션 정보|
|private|GateManager*|gate_manager|해당 스테이지의 게이트 관리자|
|private|int|game_start_frame|스테이지 시작 틱|
|private|Infoable*|panels[3]|렌더링할 객체들|

### method
|access modifier|return|name||
|--|--|--|--|
|public|Game|Game|Game| 생성자
|public|void|Init(const int stage)| 게임별 맵 저장, 게임매니저 생성자에서 각각 호출|
|public|void|setInput()|입력받은 키보드의 값 설정|
|public|void|gameStart(const int frame)|스테이지 시작 될 때 한번 호출|
|public|void|update(const int frame)| 매 프레임 게임 업데이트|
|public|bool|isClear()| update 마친 후 호출 ( 클리어 판단)|
|public|int|IsValid()| 매프레임 게임 유효성 검사|
|public|void|gameEnd()|스테이지 종료 시 한번 호출|

## GameData

### attribute
|access modifier|type|name||
|--|--|--|--|
|public|vector<vector<int>>|mo_count|평방 분할 알고리즘을 활용하면서 item을 만들수 있는 칸의 개수를 저장하는 벡터|
|public|vector<vector<Point>>|mo_points|평방 분할 알고리즘으로 나누어진 구간마다 담긴 점들의 모음을 나열한 벡터|
|public|int|sq|평방 분할 알고리즘에 사용되는 구간의 길이 및 구간의 개수|
|public|Point|next_point|뱀의 머리의 가상 다음 위치|
|public|Point|next_head_point|뱀의 머리의 실제 다음 위치|
|public|SnakeMap*|game_map|스네이크 맵 포인터|
|public|int|current_frame|현재 틱|
|public|int|current_direction|뱀의 현재 방향|
|private|vector<Point>|gates|gate의 좌표를 담아두는 벡터|
|private|vector<vector<int>>|gate_directions|gate에 진입/진출 방향에 대해 담아두는 벡터|
|private|int|key|현재 저장된 키보드 입력 방향|


### method
|access modifier|return|name||
|--|--|--|--|
|public|GameData|GameData|GameData(const int stage)|생성자|
|public|void|update(const int current_frame)|현재 틱을 업데이트한다.|
|public|int|checkItem(const Point& head)|들어오는 위치가 growth_item, poison_item, 빈칸인지에 따라 1, -1, 0을 return 한다.|
|public|vector<vector<int>>|getMap()|snakeMap의 현재 스테이지의 맵을 return한다.|
|public|void|setNextPoint(const Point& next_point)| next_point를 들어오는 점으로 변경한다.|
|public|void|setNextHeadPoint(const Point& next_head_point)|next_head_point를 들어오는 점으로 변경한다.|
|public|Point|getNextPoint()|next_point를 return한다.|
|public|Point|getNextHeadPoint()|next_head_point를 return한다.|
|public|void|setCurrentFrame(const int current_frame)|현재 틱을 업데이트한다.|
|public|int|getCurrentFrame()|현재 틱을 반환한다.|
|public|void|updateDirection()|키보드 입력 방향을 반영한다.|
|public|void|updateSnakePosition(const vector<Point>& snake_body)|현재 뱀의 위치를 맵에 새로 반영한다.|
|public|void|updateItemPosition(const vector<Point>& item_positions, const vector<int>& item_infos)|현재 아이템의 위치와 정보를 맵에 새로 반영한다.|
|public|void|updateGateDirection(bool isExist, const vector<vector<int>>& gate_directions)|현재 게이트의 위치를 맵에 새로 반영한다.|
|public|vector<Point>|getGatePositions()|gate의 위치 벡터를 반환한다.|
|public|int|getCurrentDirection()|현재 뱀의 방향을 반환한다.|
|public|void|setCurrentDirection(const int current_direction)|현재 뱀의 방향을 반영한다.|
|public|int|mapReset()|맵을 초기화한다.|
|public|int|getPositionInfo(const int x, const int y)|맵에서 들어오는 위치에 해당하는 셀의 정보를 return한다.|
|public|void|setPositionInfo(const int x, const int y, const int info)|맵에서 들어오는 위치에 해당하는 셀의 정보를 수정한다.|
|public|int|getKey()|key를 반환한다.|
|private|wchar_t|changeMap(int i)|셀의 정보를 랜더링 문자로 변경하여 반환한다.|
|public|void|Info()|화면에 Info한다.|


## GameManager

### attribute
|access modifier|type|name||
|--|--|--|--|
|private|int|frame|게임의 전체 틱|
|private|int|curStage|현재 플레이중인 스테이지|
|private|Game*|games|전체 게임 정보|
|private|Game*|curGame|현재 게임 정보|
|private|GameFlow|game_flow|게임플로우 렌더링 객체|

### method
|access modifier|return|name||
|--|--|--|--|
|public|GameManager|GameManager(GameFlow& gameflow)|생성자|
|public|void|start()|첫 스테이지 시작 전 호출|
|public|void|end()|마지막 스테이지 종료 후 ㅎ출ㅗ|
|public|void|setInput()|입력받은 키 값 세팅|
|public|int|isValid()|유효성 검사|
|public|void|update(const int frame)|게임 업데이트|
|private|void|stageSetting()|스테이지 클리어시 관련 정보들 처리|

## SnakeMap
    
### attribute

|access modifier|type|name||
|--|--|--|--|
|private|int|total_stage_count|전체 게임 스테이지의 갯수
|private|vector<vector<vector\<int>>>|total_map|Snake game 전체 맵의 초기상태를 담고 있는 3차원 벡터
|private|int|current_stage|현재 stage 번호, 0부터 시작
|private|vector<vector\<int>>|current_map|현재 stage의 맵을 담고 있는 2차원 백터

### method
|access modifier|return|name||
|--|--|--|--|
|public|SnakeMap|SnakeMap()|생성자
|public|int|getTotalMapCount()|전체 게임 stage의 개수를 반환한다.
|public|vector<vector<int>>|getCurrentMap()|currnet_map을 반환한다.
|public|int|getPositionInfo(int x, int y)|current_map[x][y]를 반환한다.
|public|void|setCurrentMap(int next_stage)|currnet_stage를 next_stage로 set하고, current_map을 totalmap[next_stage]로 변경한다.
|public|void|setPositionInfo(int x, int y, int Info)|current_map[x][y]를 info로 변경한다. info로 들어오는 숫자는 [참고사항의 SnakeMap 요소 번호 목록](##참고) 확인
|public|void|update(vector<Point> snake, vector<Point> gates, vector<Point> items)|뱀, 게이트, 아이템 정보를 맵에 반영한다. 


## Snake

### attribute
|access modifier|type|name||
|--|--|--|--|
|private|Point|next_pos|머리가 향할 다음 위치|
|private|Point|head_pos|머리의 현재 위치|
|private|vector<Point>|bodies|스네이크 몸들의 위치|

### 멤버 함수
|access modifier|return|name||
|--|--|--|--|
|public|Snake|Snake()|생성자|
|public|void|update(GameData& game_data, UserData& user_data)|뱀의 움직임 업데이트|
|public|Point|getNextPoint(const int curDir)|유효성 검사할 때 뱀의 다음 머리 위치 반환|
|public|int|getSnakeLength()|뱀의 길이 반환|

## Mission

### attribute

|access modifier|type|name||
|--|--|--|--|
|private|vertor\<bool>|current_mission_state|현재 미션 하나하나의 클리어 상태
|private|vector\<int>|current_mission_list|현재 라운드의 미션 목록
|private|vector\<int>|total_mission_list|모든 라운드의 미션 목록
|private|vector\<int>|current_state|현재 게임의 상태

### method

|access modifier|return|name||
|--|--|--|--|
|public|void|isComplete|미션이 클리어되었는지 확인한다.
|public|int|Info|미션을 화면에 표시한다.
|public|Mission|Mission|Mission(const int stage)|생성자

    

## Item
### attribute
|access modifier|type|name||
|--|--|--|--|
|private|Point|pos|아이템의 위치(positon)
|private|int|kinds|아이템의 종류|1: growth item/2: posion item
|private|int|created_frame|아이템 생성 시기 

### method
|access modifier|return|name||
|--|--|--|--|
|public|Item|Item|생성자
|public|int|getKinds()|아이템의 종류반환
|public|int|getCreatedFrame()|아이템 생성 시기 반환
|public|void|setPos(const Point pos)|아이템의 위치 설정
|public|void|setKinds(const int kinds)|아이템의 종류 설정
|public|void|setCreatedFrame(const int frame)|아이템 생성 시기 설정
|public|Point|getPos()|아이템의 위치 반환


## ItemManager

### attribute

|access modifier|type|name||
|--|--|--|--|
|private|int|last_made_frame|가장 최근 아이템을 만든 틱
|private|int|delay|아이템을 만든 후 다음 아이템을 만들 때 까지의 틱
|private|int|growth_odd|아이템을 만들 때 성장 아이템이 나올 확률
|private|int|disappear_frame|아이템이 사라지는 틱
|public|vector\<Item>|items|현재 존재하는 아이템 목록

### method

|access modifier|return|name||
|--|--|--|--|
|public|ItemManager|ItemManager|생성
|public|void|makeItem(int current_frame, const vector<vector<int>>& map, GameData &game_data)|아이템을 만들 조건이 되면 아이템을 만든다.
|public|int|eatItem(const Point& next_head_point, GameData &game_data)|Snake의 다음 머리 위치가 아이템이라면 아이템의 정보를 리턴하고 그 아이템을 삭제한다.
|public|void|deleteItem(const int current_frame, GameData game_data|어떠한 아이템이 너무 오래 생성되어있으면 그 아이템을 삭제한다.
|public|void|update(GameData &game_data, Userdata &user_data)|아이템의 정보를 업데이트한다.


## GateManager

### attribute

||type|name||
|--|--|--|--|
|private|const int|GATE_MANAGER_IMMUNE_WALL|
|private|pair<Point, Point>|gates|생성된 gates를 가지고 있음
|private|pair<vector<int>, vector<int>>|gate_directions|gate로 나갈 방향
|private|bool|is_passing|뱀이 통과중이면 true, 아니면 false
|private|int|live_time|게이트 생존시간
|private|int|snake_entered_frame| 뱀이 게이트에 처음 들어간 틱
|private|int|last_gate_deleted_frame|게이트가 삭제된 틱
|private|int|wall_map[MAP_X][MAP_Y]|벽이 있는 곳 표시
|private|vector<Point>|wall_list[100]|벽의 좌표
|private|int|check_wall[MAP_X * MAP_Y]|
|private|int|wall_count|벽 뭉텅이의 개수
|private|bool|isExist|게이트가 존재 여부
|private|const int|DIR_PRIORITY_TABLE[5][5]|방향 우선순위 테이블


### method

||return|name||
|--|--|--|--| 
|private|void makeWallMap(const int num, const int x, const int y)|맵으로부터 벽을 체크하는 메서드
|private|vector\<int>|makeGateDirection(Point gate)|게이트 나가는 방향을 구하는 메서드
|public|GateManager|GateManager(vector<vector<int>> game_map)|생성자
bool|isPassing()| 매 프레임 호출되어서 게이트 유효성 체크
|public|void|makeNewGate()|새로운 게이트 생성
|public|void|update(GameData &game_data, UserData &user_data)|매 틱마다 업데이트
|public|pair<Point, Point>|getGates()|게이트 반환

## UserData
 - 생성자
    - UserData(){
        int current_length = 3;
        int max_length = 3;
        int growth_item_count = 0;
        int posion_item_count = 0;
        int used_gate_length = 0;

        window;
    }
    - UserData(int current_length, int max_length, int growth_item_count, int posion_item_count, int used_gate_count)

### attribute
||type|name||
|--|--|--|--|
|private|int|current_length|현재 뱀의 길이
|private|int|max_length|현 라운드의 뱀의 최대 길이
|private|int|growth_item_count|성장 아이템을 먹은 횟수
|private|int|posion_item_count|독 아이템을 먹은 횟수
|private|int|used_gate_count|게이트를 사용한 횟수

### method
||return|name||
|--|--|--|--|
|public|int|getCurrentLength()|현재 길이 반환
|public|void|setCurrentLength(int current_length)|현재 길이 설정
|public|int|getMaxLength()|최대 길이 반환
|public|void|setMaxLength(int max_length)|최대 길이 설정
|public|int|getGrowthItemCount()|성장 아이템 먹은 횟수 반환
|public|void|setGrowthItemCount(int Growth_item_count)|성장 아이템 먹은 횟수 설정
|public|int|getPosionItemCount()|감소 아이템 먹은 횟수 반환
|public|void|setPosionCount(int posion_item_count)|감소 아이템 먹은 횟수 설정
|public|int|getUsedGateCount()|게이트 사용 횟수 반환
|public|void|setUsedGateCount(int used_gate_count)|게이트 사용 횟수 설정
|public|void|GrowthItemIncrease()|성장아이템 먹은 횟수+1
|public|void|PoisonItemIncrease()|감소아이템 먹은 횟수+1
|public|void|UsedGateCountIncrease()|게이트를 사용한 횟수+1
|public|void|Info()|Userdata를 window에 렌더링

## Point

### attribute
||type|name||
|--|--|--|--|
|public|int|x|x 좌표
|public|int|y|y 좌표

### method
||return|name||
|--|--|--|--| 
|public|Point|Point()|생성자
|public|Point|Point(int x, int y)|생성자
|public|bool|isValid()|유효한 좌표 여부
|public|Point|moveTo(const int curDir)|그 좌표에서 이동했을 때 좌표 
|--|--|--|--|
|public|int|x|x 좌표
|public|int|y|y 좌표

### method
||return|name||
|--|--|--|--| 
|public|Point|Point()|생성자
|public|Point|Point(int x, int y)|생성자
|public|bool|isValid()|유효한 좌표 여부
|public|Point|moveTo(const int curDir)|그 좌표에서 이동했을 때 좌표 
|public|friend bool|operator==(const Point& x, const Point& y)
|public|Point&|operator=(const Point& a)
|public|friend ostream&|operator<<(std::ostream& outStream, const Point& point)

## 참고

### SnakeMap 요소 번호 목록
- 움직여도 되는 곳 : 0 
- SNAKE_HEAD : 1
- SNAKE: 2
- WALL : 3
- IMMUNE_WALL: 4
- GATE: 5
- GROWTH_ITEM: 6 
- POSION_ITEM: 7
