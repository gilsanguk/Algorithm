-- 코드를 입력하세요
SELECT first_half.flavor
from first_half join icecream_info
on first_half.flavor = icecream_info.flavor
where icecream_info.ingredient_type = 'fruit_based' and first_half.total_order > 3000
order by first_half.total_order desc