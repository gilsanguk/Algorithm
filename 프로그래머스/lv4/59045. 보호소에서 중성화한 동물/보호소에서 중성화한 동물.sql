-- 코드를 입력하세요
SELECT animal_outs.animal_id, animal_outs.animal_type, animal_outs.name
from animal_outs join animal_ins
on animal_outs.animal_id = animal_ins.animal_id
where (animal_outs.sex_upon_outcome Like 'Spayed%' or animal_outs.sex_upon_outcome Like 'Neutered%') and animal_ins.sex_upon_intake Like 'Intact%'
order by animal_outs.animal_id
