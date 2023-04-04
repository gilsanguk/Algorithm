-- 코드를 입력하세요
SELECT FOOD_TYPE, REST_ID, REST_NAME, FAVORITES
from REST_INFO
where (FOOD_TYPE, favorites) in (SELECT FOOD_TYPE, MAX(FAVORITES)
                             from REST_INFO
                             group by food_type)
order by FOOD_TYPE desc;