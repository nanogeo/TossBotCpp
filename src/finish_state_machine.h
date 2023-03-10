#pragma once
#include <string>

#include "sc2api/sc2_interfaces.h"
#include "sc2api/sc2_agent.h"
#include "sc2api/sc2_unit_filters.h"

#include "TossBot.h"

namespace sc2 {

class State
{
public:
    TossBot* agent;
    State() {};
    virtual std::string toString();
    virtual void TickState();
    virtual void EnterState();
    virtual void ExitState();
    virtual State* TestTransitions();
};

#pragma region Oracle

class OracleDefend : public State {
public:
    Units oracles;
    std::vector<float> time_last_attacked;
    std::vector<bool> has_attacked;
    Point2D denfensive_position;
    OracleDefend(TossBot* agent, Units oracles, Point2D point)
    {
        this->agent = agent;
        this->oracles = oracles;
        for (int i = 0; i < oracles.size(); i++)
        {
            time_last_attacked.push_back(0);
            has_attacked.push_back(true);
        }
        denfensive_position = point;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;

    void OnUnitDamagedListener(const Unit*, float, float);
    void OnUnitDestroyedListener(const Unit*);
};

class OracleScout : public State {
public:
    Units oracles;
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class OracleHarass : public State {
public:
    Units oracles;
    Point2D pos;
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class OracleCoverArmy : public State {
public:
    Units oracles;
    Point2D army_center;
    float danger_level;
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

#pragma endregion

#pragma region Chargelot Allin

class ChargelotAllInStateMachine;

class ChargeAllInMovingToWarpinSpot : public State {
public:
    ChargelotAllInStateMachine* state_machine;
    ChargeAllInMovingToWarpinSpot(TossBot* agent, ChargelotAllInStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ChargeAllInWarpingIn : public State {
public:
    ChargelotAllInStateMachine* state_machine;
    ChargeAllInWarpingIn(TossBot* agent, ChargelotAllInStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

#pragma endregion

#pragma region Scout Z

class ScoutZergStateMachine;

class ScoutZInitialMove : public State
{
public:
    ScoutZergStateMachine* state_machine;
    ScoutZInitialMove(TossBot* agent, ScoutZergStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ScoutZScoutMain : public State
{
public:
    ScoutZergStateMachine* state_machine;
    ScoutZScoutMain(TossBot* agent, ScoutZergStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ScoutZScoutNatural : public State
{
public:
    ScoutZergStateMachine* state_machine;
    ScoutZScoutNatural(TossBot* agent, ScoutZergStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ScoutZLookFor3rd : public State
{
public:
    ScoutZergStateMachine* state_machine;
    ScoutZLookFor3rd(TossBot* agent, ScoutZergStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

#pragma endregion

#pragma region Scout T

class ScoutTerranStateMachine;

class ScoutTInitialMove : public State
{
public:
    ScoutTerranStateMachine* state_machine;
    ScoutTInitialMove(TossBot* agent, ScoutTerranStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ScoutTScoutMain : public State
{
public:
    ScoutTerranStateMachine* state_machine;
    ScoutTScoutMain(TossBot* agent, ScoutTerranStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

class ScoutTScoutNatural : public State
{
public:
    ScoutTerranStateMachine* state_machine;
    ScoutTScoutNatural(TossBot* agent, ScoutTerranStateMachine* state_machine)
    {
        this->agent = agent;
        this->state_machine = state_machine;
    }
    virtual std::string toString() override;
    void TickState() override;
    virtual void EnterState() override;
    virtual void ExitState() override;
    virtual State* TestTransitions() override;
};

#pragma endregion

#pragma region ImmortalDrop

class ImmortalDropStateMachine;

class ImmortalDropWaitForImmortals : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	ImmortalDropWaitForImmortals(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropInitialMove : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	ImmortalDropInitialMove(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropMicroDrop : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	bool first_immortal_turn = true;
	bool immortal1_has_attack_order = false;
	bool immortal2_has_attack_order = false;
	ImmortalDropMicroDrop(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropMicroDropCarrying1 : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	int entry_frame;
	ImmortalDropMicroDropCarrying1(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
		entry_frame = agent->Observation()->GetGameLoop();
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropMicroDropCarrying2 : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	int entry_frame;
	ImmortalDropMicroDropCarrying2(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
		entry_frame = agent->Observation()->GetGameLoop();
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropMicroDropDropped1 : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	bool immortal1_has_attack_order = false;
	bool immortal2_has_attack_order = false;
	ImmortalDropMicroDropDropped1(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropMicroDropDropped2 : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	bool immortal1_has_attack_order = false;
	bool immortal2_has_attack_order = false;
	ImmortalDropMicroDropDropped2(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropWaitForShields : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	ImmortalDropWaitForShields(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};

class ImmortalDropLeave : public State
{
public:
	class ImmortalDropStateMachine* state_machine;
	ImmortalDropLeave(TossBot* agent, ImmortalDropStateMachine* state_machine)
	{
		this->agent = agent;
		this->state_machine = state_machine;
	}
	virtual std::string toString() override;
	void TickState() override;
	virtual void EnterState() override;
	virtual void ExitState() override;
	virtual State* TestTransitions() override;
};


#pragma endregion

class StateMachine
{
public:
    TossBot* agent;
    State* current_state;
    std::string name;
    StateMachine() {}
    StateMachine(TossBot* agent, State* starting_state, std::string name) {
        this->agent = agent;
        current_state = starting_state;
        this->name = name;
        current_state->EnterState();
    }
    virtual void RunStateMachine()
    {
        State* new_state = current_state->TestTransitions();
        if (new_state != NULL)
        {
            current_state->ExitState();
            delete current_state;
            current_state = new_state;
            current_state->EnterState();
        }
        current_state->TickState();
    }

    virtual void StartStateMachine()
    {
        return;
    }

    State* GetState()
    {
        return current_state;
    }

    std::string toString()
    {
        return name + " - " + current_state->toString();
    }
};

class OraclePvZStateMachine : public StateMachine
{
    std::vector<const Unit*> oracles;
    float last_scout_time;
};

class ChargelotAllInStateMachine : public StateMachine
{
public:
    Units zealots;
    const Unit* prism;
    float last_warp_in_time;
    std::vector<Point2D> prism_spots;
    int prism_spots_index;
    Point2D next_warp_in_location;
    ChargelotAllInStateMachine(TossBot* agent, std::string name, std::vector<Point2D> prism_locations, Units zealots, const Unit* prism, float last_warp_in_time) {
        this->agent = agent;
        this->name = name;
        current_state = new ChargeAllInMovingToWarpinSpot(agent, this);
        prism_spots = prism_locations;
        this->zealots = zealots;
        this->prism = prism;
        this->last_warp_in_time;
        prism_spots_index = 0;
        current_state->EnterState();
    }
};

class ScoutZergStateMachine : public StateMachine
{
public:
    const Unit* scout;
    Point2D enemy_main;
    int index;
    std::vector<Point2D> main_scout_path;
    std::vector<Point2D> natural_scout_path;
    std::vector<Point2D> possible_3rds;
    Point2D enemy_natural_pos;
    Point2D current_target;
    ScoutZergStateMachine(TossBot* agent, std::string name, const Unit* scout, Point2D enemy_main, std::vector<Point2D> main_scout_path, std::vector<Point2D> natural_scout_path, Point2D enemy_natural_pos, std::vector<Point2D> possible_3rds)
    {
        this->agent = agent;
        this->name = name;
        current_state = new ScoutZInitialMove(agent, this);
        this->scout = scout;
        this->enemy_main = enemy_main;
        this->main_scout_path = main_scout_path;
        this->natural_scout_path = natural_scout_path;
        this->enemy_natural_pos = enemy_natural_pos;
        this->possible_3rds = possible_3rds;

        current_state->EnterState();
    }

    void RunStateMachine()
    {
        StateMachine::RunStateMachine();
        CheckScoutingInfo();
    }


    void CheckScoutingInfo()
    {
        for (const auto &unit : agent->Observation()->GetUnits())
        {
            if (unit->alliance == Unit::Alliance::Enemy && unit->display_type == Unit::DisplayType::Visible)
            {
                if (unit->unit_type.ToType() == UNIT_TYPEID::ZERG_SPAWNINGPOOL && agent->scout_info_zerg.pool_timing == 0)
                {
                    std::cout << "pool built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_zerg.pool_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::ZERG_ROACHWARREN && agent->scout_info_zerg.roach_warren_timing == 0)
                {
                    std::cout << "roach warren built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_zerg.roach_warren_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::ZERG_EXTRACTOR && agent->scout_info_zerg.gas_timing == 0)
                {
                    std::cout << "gas built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_zerg.gas_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::ZERG_HATCHERY && agent->scout_info_zerg.natural_timing == 0)
                {
                    if (Distance2D(unit->pos, enemy_natural_pos) < 2)
                    {
                        std::cout << "natural built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                        agent->scout_info_zerg.natural_timing = agent->GetTimeBuilt(unit);
                    }
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::ZERG_HATCHERY && agent->scout_info_zerg.third_timing == 0)
                {
                    for (const auto &pos : possible_3rds)
                    {
                        if (Distance2D(unit->pos, pos) < 2)
                        {
                            std::cout << "third built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                            agent->scout_info_zerg.third_timing = agent->GetTimeBuilt(unit);
                        }
                    }
                }
            }
        }
    }
};

class ScoutTerranStateMachine : public StateMachine
{
public:
    const Unit* scout;
    Point2D enemy_main;
    int index;
    std::vector<Point2D> main_scout_path;
    std::vector<Point2D> natural_scout_path;
    Point2D enemy_natural_pos;
    Point2D current_target;
    ScoutTerranStateMachine(TossBot* agent, std::string name, const Unit* scout, Point2D enemy_main, std::vector<Point2D> main_scout_path, std::vector<Point2D> natural_scout_path, Point2D enemy_natural_pos)
    {
        this->agent = agent;
        this->name = name;
        current_state = new ScoutTInitialMove(agent, this);
        this->scout = scout;
        this->enemy_main = enemy_main;
        this->main_scout_path = main_scout_path;
        this->natural_scout_path = natural_scout_path;
        this->enemy_natural_pos = enemy_natural_pos;

        current_state->EnterState();
    }

    void RunStateMachine()
    {
        StateMachine::RunStateMachine();
        CheckScoutingInfo();
    }


    void CheckScoutingInfo()
    {
        for (const auto &unit : agent->Observation()->GetUnits())
        {
            if (unit->alliance == Unit::Alliance::Enemy && unit->display_type == Unit::DisplayType::Visible)
            {
                if (unit->unit_type.ToType() == UNIT_TYPEID::TERRAN_BARRACKS && agent->scout_info_terran.barrackes_timing == 0)
                {
                    std::cout << "barracks built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_terran.barrackes_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::TERRAN_FACTORY && agent->scout_info_terran.factory_timing == 0)
                {
                    std::cout << "factory built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_terran.factory_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::TERRAN_COMMANDCENTER && agent->scout_info_terran.natural_timing == 0 && unit->build_progress < 1)
                {
                    std::cout << "natural built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_terran.natural_timing = agent->GetTimeBuilt(unit);
                }
                else if (unit->unit_type.ToType() == UNIT_TYPEID::TERRAN_REFINERY && agent->scout_info_terran.gas_timing == 0)
                {
                    std::cout << "gas built at " << std::to_string(agent->GetTimeBuilt(unit)) << std::endl;
                    agent->scout_info_terran.gas_timing = agent->GetTimeBuilt(unit);
                }
            }
        }
    }
};

class ImmortalDropStateMachine : public StateMachine
{
public:
	const Unit* immortal1;
	const Unit* immortal2;
	const Unit* prism;
	Point2D entry_pos;
	std::vector<Point2D> prism_path;
	int path_index;
	std::vector<UNIT_TYPEID> target_priority = { UNIT_TYPEID::TERRAN_CYCLONE, UNIT_TYPEID::TERRAN_THOR, UNIT_TYPEID::TERRAN_SIEGETANKSIEGED, UNIT_TYPEID::TERRAN_SIEGETANK,
		UNIT_TYPEID::TERRAN_MULE, UNIT_TYPEID::TERRAN_MARAUDER, UNIT_TYPEID::TERRAN_MARINE, UNIT_TYPEID::TERRAN_SCV, UNIT_TYPEID::TERRAN_WIDOWMINE, UNIT_TYPEID::TERRAN_TECHLAB, UNIT_TYPEID::TERRAN_REACTOR };
	ImmortalDropStateMachine(TossBot* agent, std::string name, const Unit* immortal1, const Unit* immortal2, const Unit* prism, Point2D entry_pos, std::vector<Point2D> prism_path) {
		this->agent = agent;
		this->name = name;
		current_state = new ImmortalDropWaitForImmortals(agent, this);
		this->immortal1 = immortal1;
		this->immortal2 = immortal2;
		this->prism = prism;
		this->prism_path = prism_path;
		this->entry_pos = entry_pos;
		path_index = 0;
		current_state->EnterState();
	}

	Point2D UpdatePrismPathing()
	{
		// if theres a tank then go ontop of it
		if (agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_SIEGETANKSIEGED)).size() > 0)
		{
			return agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_SIEGETANKSIEGED))[0]->pos;
		}
		if (agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_SIEGETANK)).size() > 0)
		{
			return agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_SIEGETANK))[0]->pos;
		}
		// if theres a cyclone then go ontop of it?
		if (agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_CYCLONE)).size() > 0)
		{
			return agent->Observation()->GetUnits(IsUnit(UNIT_TYPEID::TERRAN_CYCLONE))[0]->pos;
		}

		int prev_index = path_index - 1 >= 0 ? path_index - 1 : prism_path.size() - 1;
		int next_index = path_index + 1 < prism_path.size() ? path_index + 1 : 0;

		// update path index
		if (Distance2D(prism->pos, prism_path[prev_index]) < 2)
		{
			path_index = prev_index;
			prev_index = path_index - 1 >= 0 ? path_index - 1 : prism_path.size() - 1;
			next_index = path_index + 1 < prism_path.size() ? path_index + 1 : 0;
		}
		else if (Distance2D(prism->pos, prism_path[next_index]) < 2)
		{
			path_index = next_index;
			prev_index = path_index - 1 >= 0 ? path_index - 1 : prism_path.size() - 1;
			next_index = path_index + 1 < prism_path.size() ? path_index + 1 : 0;
		}

		// move away from danger?
		std::cout << agent->DangerLevelAt(prism, prism_path[prev_index]) << std::endl;
		if (agent->DangerLevelAt(prism, prism_path[prev_index]) > 0 && agent->DangerLevelAt(prism, prism_path[prev_index]) < agent->DangerLevelAt(prism, prism_path[next_index]))
			return prism_path[prev_index];
		else
			return prism_path[next_index];

	}

};



}
